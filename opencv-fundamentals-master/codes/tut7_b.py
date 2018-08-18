import cv2
import numpy as np


img = cv2.imread('blueball.png',cv2.IMREAD_COLOR)

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# hsv hue sat value
lower_red = np.array([80, 50, 0])
upper_red = np.array([255, 150, 255])

mask = cv2.inRange(img, lower_red, upper_red)

res = cv2.bitwise_and(img, img, mask=mask)

cv2.imshow('initial image',img)
cv2.imshow('mask', mask)
cv2.imshow('res', res)


cv2.waitKey(0)
cv2.destroyAllWindows()
