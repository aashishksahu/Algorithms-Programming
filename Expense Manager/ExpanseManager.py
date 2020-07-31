"""
    CLI Expanse Manager

    Simple CL application to store transaction details in a database
    author: Aashish K Sahu
"""


class Structs:
    """
        this class holds data structures containing prepositions and currency keywords
        which are used to match with the words from input string during parsing

        This class serves as base class for "Parser"
    """

    # list of prepostions
    # it'll be used to find keywords with context to position and time
    prepositions = ["on", "at", "in", "for", "by"]

    # list of currency
    curr = ["rs", "rs."]

    # list of month words
    time_stamp = ["jan", "january", "feb", "february", "mar", "march", "apr", "april", "may", "jun", "june",
                  "jul", "july", "aug", "august", "sep", "sept", "september", "oct", "october", "nov",
                  "november", "dec", "december"]


class Parser(Structs):
    """
        this class prepares and processes the text input to extract
        1. amount
        2. description
        3. date

        STEP 1: numbers are extracted
        STEP 2: if words before number is a preposition and word after the number
                is a month or vice versa and the number itself is of two digits, it is a date
                else if words before or after the number is a currency keyword, it
                is the amount
                if word after preposition is not a month or number, it is the description
        STEP 3: pass the data, amount & Description to function addToDB for insertion in database
    """

    def __init__(self, text):
        """
        initialize the instance with the user input string

        text: user input string
        """
        self.text = text

    def checker(self):
        """
        extracts amount, date & Description from text input
        """

        amount = 0
        desc = ""
        date = ""

        # split the text at spaces
        string = self.text.lower().split(" ")

        # loop over all the words
        for i in range(len(string)):
            # check if the word is not a number
            if not string[i].isdigit():
                # check if the word before is a preposition
                if i > 0 and string[i-1] in self.prepositions:
                    # if there are multiple words for description
                    if i != len(string)-1 and (string[i+1] == "&" or string[i+1] == "and"):
                        desc = ' '.join(string[i:i+2])
                    else:
                        desc = string[i]
                # if a month name occurs after preposition
                elif i > 0 and string[i-1] in self.prepositions and string[i] in self.time_stamp:
                    date = str(string[i+1]+" "+string[i])
            # if word is a number
            elif string[i].isdigit():
                # is there a currency word before or after the word
                if string[i-1] in self.curr or string[i+1] in self.curr:
                    amount = float(string[i])
                # if it is a number but not surrounded by currency word, it is a date
                elif string[i-1] in self.time_stamp:
                    # if the date number is written after the month
                    date = str(string[i] + " " + string[i-1])
                elif string[i+1] in self.time_stamp:
                    # if the date number is written before the month
                    date = str(string[i] + " " + string[i+1])

        # splitting date and month
        date = date.split(" ")
        if int(date[0]) < 0 or int(date[0]) > 31:
            print("date can't be greater than 31 or less than 1...")
            return

        return {"date": date[0],
                "month": date[1],
                "amount": amount,
                "desc": desc}


