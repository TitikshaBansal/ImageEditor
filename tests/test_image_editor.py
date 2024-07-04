import cv2
import pytest

# Dummy functions for illustration purposes
# Replace these with your actual function implementations

def load_image(path):
    img = cv2.imread(path, cv2.IMREAD_COLOR)
    return img

def convert_to_gray(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    return gray

# Test to check if an image is loaded successfully
def test_load_image():
    path = 'tests/test_image.jpg'
    img = load_image(path)
    assert img is not None, "Image should be loaded correctly"

# Test to check if an image is converted to grayscale
def test_convert_to_gray():
    path = 'tests/test_image.jpg'
    img = load_image(path)
    gray_img = convert_to_gray(img)
    assert len(gray_img.shape) == 2, "Image should be converted to grayscale"
    assert gray_img is not None, "Grayscale image should not be None"

if __name__ == "__main__":
    pytest.main()
