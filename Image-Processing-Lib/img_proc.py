import numpy as np
from PIL import Image
import os 



class img_proc:
    # image processing toolkit 
    # this class reads and writes image to disk

    def load_img(self, path):
        """
            loads an image or all the images in a directory

            path: location of an image or a directory of images 
        """

        # check if it is a directory or a file
        if os.path.isfile(path):
            img_file = Image.open(path)
            return img_file
        elif os.path.isdir(path):
            # list all the files in the directory
            file_list = os.listdir(path)
            # load all the images in library
            img_list  = [Image.open(path+"/"+name) for name in file_list]
            return img_list
        else:
            print("invalid path!")
            return


    def store_img(self, img_file, name):
        """
            img: np array of the image
            name: save name
            
            functions saves the imageon disk
        """
        
        # Ensure the pixel-values are between 0 and 255.
        image = np.clip(img_file, 0.0, 255.0)
        
        # Convert to bytes.
        image = image.astype(np.uint8)
        
        # Write the image-file in jpeg-format.
        with open(name, 'wb') as file:
            Image.fromarray(image).save(file, 'jpeg')

    def display(self, img):
        # displays the image
        if isinstance(img, np.ndarray):
            img = np.clip(img, 0.0, 255.0)
            img = Image.fromarray(np.uint8(img))

        img.show()


    def crop(self, img, dims):
        """
            crops a region of image starting from (x1, y1) to (x2, y2)

        """

        # check if the image is a numpy array or not
        if not isinstance(img, np.ndarray):
            # convert image to numpy array
            img = np.asarray(img)

        return img[dims[0]:dims[3], dims[1]:dims[2]]


    def rotate90(self, img):
        """
            rotates an image by 90 degrees
        """

        # check if the image is a numpy array or not
        if not isinstance(img, np.ndarray):
            # convert image to numpy array
            img = np.asarray(img)

        return np.transpose(img)



obj = img_proc()
file = obj.load_img("/home/aashish/Pictures/101078.jpg")

f = obj.rotate90(file)
obj.display(f)