import cv2
import numpy as np

img = cv2.imread('blueball.png',cv2.IMREAD_COLOR)


laplacian = cv2.Laplacian(img, cv2.CV_64F)
sobelx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize = 5)
sobely = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize = 5)
edges = cv2.Canny(img, 100,200)



cv2.imshow('image',img)
cv2.imshow('laplacian',laplacian)
cv2.imshow('sobelx',sobelx)
cv2.imshow('sobely',sobely)
cv2.imshow('edges',edges)


cv2.waitKey(0)
cv2.destroyAllWindows()
