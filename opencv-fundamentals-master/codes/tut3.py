import cv2
import numpy as np

img = cv2.imread('spongebob.jpg', cv2.IMREAD_COLOR)

cv2.line(img, (0,0),  (500,500),(255,255,255), 15) #BGR in opencv
cv2.rectangle(img, (0,0),(50,50), (255,0,0), 5)
cv2.circle(img, (100,63), 55, (0,0,255), -1)

pts = np.array([[10,60],[50,300],[100,20],[60,60]], np.int32)

cv2.polylines(img, [pts], True, (0,255,255), 2)

font = cv2.FONT_HERSHEY_SIMPLEX

cv2.putText(img,'OpenCV Tuts!', (0,130), font, 1, (0,100,255), 5, cv2.LINE_AA)
cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()



