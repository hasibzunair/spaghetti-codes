import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('picture.png',cv2.IMREAD_GRAYSCALE)
img1 = cv2.imread('picture.png',cv2.IMREAD_COLOR)


cv2.imshow('panda',img1)
cv2.imshow('processed panda',img)

cv2.waitKey(0)
cv2.destroyAllWindows()











#plt.imshow(img, cmap = 'gray', interpolation = 'bicubic')
#plt.xticks([]), plt.yticks([])  # to hide tick values on X and Y axis
#plt.plot([200,300,400],[100,200,300],'c', linewidth=5)
#plt.show()

#cv2.imwrite('picture.jpeg',img)
