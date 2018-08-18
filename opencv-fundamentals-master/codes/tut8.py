import cv2
import numpy as np


img = cv2.imread('blueball.png',cv2.IMREAD_COLOR)

hsv = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# hsv hue sat value
lower_red = np.array([80, 50, 0])
upper_red = np.array([255, 150, 255])

mask = cv2.inRange(img, lower_red, upper_red)

res = cv2.bitwise_and(img, img, mask=mask)

kernel = np.ones((15,15), np.float32)/255
smoothed = cv2.filter2D(res, -1,kernel) #blur1
blur = cv2.GaussianBlur(res, (15,15), 0) #blur 2
median = cv2.medianBlur(res,15) #blur 3
bilateral = cv2.bilateralFilter(res, 15, 75, 75) #blur 4



cv2.imshow('initial image',img)
#cv2.imshow('mask', mask)
cv2.imshow('res', res)
cv2.imshow('smoothed',smoothed)
cv2.imshow('blur',blur)
cv2.imshow('median',median)
cv2.imshow('bilateral',bilateral)


cv2.waitKey(0)
cv2.destroyAllWindows()
