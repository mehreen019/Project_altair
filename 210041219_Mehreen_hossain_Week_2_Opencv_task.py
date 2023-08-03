import cv2 as cv
import numpy as np

def detect_red_and_white_regions(img):
    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

    lower_red = np.array([160, 100, 100])
    upper_red = np.array([180, 255, 255])

    lower_white = np.array([0,0, 168])
    upper_white = np.array([172,50,255])

    mask1 = cv.inRange(hsv, lower_red, upper_red)
    mask2 = cv.inRange(hsv, lower_white, upper_white)

    red_image = cv.bitwise_and(img, img, mask=mask1)
    white_image = cv.bitwise_and(img,img, mask=mask2)

    cv.imshow('original', img)
    cv.imshow('red detection', red_image)
    cv.imshow('white detection', white_image)
    cv.waitKey(0)



def analyze_goat(img):
    blank = np.zeros(img.shape[:2], dtype='uint8')
    height, width= img.shape
    max_pix = 0
    min_pix = 255
    all_pix = 0
    
    for i in range(height):
        for j in range(width):
            if(img[i,j] > max_pix): max_pix = img[i,j]
            if(img[i,j] < min_pix): min_pix = img[i,j]
            
            all_pix = all_pix+ img[i,j]
    
    avg = all_pix / (height*width)
    
    canny = cv.Canny(img, 40, 255)
    contour, hier = cv.findContours(canny, cv.RETR_LIST, cv.CHAIN_APPROX_SIMPLE)
    cv.drawContours(blank, contour, -1, (255,255,255), 1)
    bin_img = cv.bitwise_and(img,img, mask=blank)
    
    print("maximum pixel value: " , max_pix )
    print("minimum pixel value: ", min_pix)
    print("average: ", avg)
    
    fcount = cv.countNonZero(bin_img)
    bcount = (height*width) - fcount
    print("foreground pixels: ", fcount)
    print("background pixels: ", bcount)
    #cv.imshow('img', bin_img)
    #cv.waitKey(0)
    
    

def analyze_goat_using_builtin_func(img):
    height, width= img.shape
    
    min_val, max_val, min_loc, max_loc = cv.minMaxLoc(img)
    avg = cv.mean(img)[0]
    
    thres_val, thres_img= cv.threshold(img, 100, 255, cv.THRESH_BINARY)
    
    print("maximum pixel value (alt): " , max_val )
    print("minimum pixel value (alt): ", min_val)
    print("average (alt): ", avg)
    
    fcount = cv.countNonZero(thres_img)
    bcount = (height*width) - fcount
    print("foreground pixels(alt): ", fcount)
    print("backgrounf pixels(alt): ", bcount)



img = cv.imread('GOAT.jpg')
detect_red_and_white_regions(img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
analyze_goat(gray)
analyze_goat_using_builtin_func(gray)