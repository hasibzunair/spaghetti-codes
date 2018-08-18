import cv2
import numpy as np

img = cv2.imread('blueball.png',cv2.IMREAD_COLOR)

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# hsv hue sat value
lower_red = np.array([80, 50, 0])
upper_red = np.array([255, 150, 255])

mask = cv2.inRange(img, lower_red, upper_red)
res = cv2.bitwise_and(img, img, mask=mask)

kernel = np.ones((5, 5), np.uint8)

#erosion dilation
erosion = cv2.erode(mask, kernel, iterations=1)
dilation = cv2.dilate(mask, kernel, iterations=1)

#opening closing
opening = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
closing = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)

#  It is the difference between input image and Opening of the image
    #cv2.imshow('Tophat',tophat)

#  It is the difference between the closing of the input image and input image.
    #cv2.imshow('Blackhat',blackhat)


cv2.imshow('Original', img)
cv2.imshow('Mask', mask)

cv2.imshow('Erosion', erosion)
cv2.imshow('Dilation', dilation)

cv2.imshow('opening', opening)
cv2.imshow('closing', closing)


cv2.waitKey(0)
cv2.destroyAllWindows()
