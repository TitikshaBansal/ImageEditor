# Console-Based Image Editor

!Image Editor 
![Image Editor Demo](demo.gif)

## Overview
The **Console-Based Image Editor** is a C++ project that allows users to manipulate images via the command-line interface. It leverages the powerful OpenCV library to provide essential image editing functionalities such as applying filters, adjusting colors, cropping, resizing, and saving images, making it suitable for various applications and users looking for a lightweight, console-driven editing solution. Whether you're a beginner or an experienced developer, this project serves as a great learning resource for image processing and console-based applications.

## Features
1. **Image Loading and Display**: Load an image from a disk and display it directly in the console.
2. **Basic Editing Operations**:
   - **Grayscale Conversion**: Convert the loaded image to grayscale.
   - **Blur**: Apply Gaussian blur to the image.
   - **Sharpening**: Enhance image sharpness.
   - **Color Adjustment**: Modify the color palette of the image.
   - **Brightness Adjustment**: Adjust the overall brightness.
   - **Contrast Enhancement**: Improve image contrast.
   - **Crop Image**: Select a region of interest (ROI) and crop the image.
   - **Resize Image**: Change the dimensions of the loaded image.
3. **Saving Edited Images**: Save the modified image back to disk.

## Distinction Points
1. **Console Interface**: Designed for simplicity and accessibility, catering to users comfortable with command-line interactions.
2. **Modular Architecture**: Organized into separate modules for image processing functions, utilities, and main program logic, enhancing maintainability and scalability.
3. **Efficient Image Handling**: Utilizes OpenCV’s robust image processing capabilities to ensure high-quality edits and fast performance.

## Technologies Used
1. **C++**: A programming language for core implementation.
2. **OpenCV**: Library for image processing tasks, providing a wide range of functions for manipulating images.
3. **Git**: Version control system for collaborative development and project management.

## Getting Started
1. **Prerequisites**:
    - C++ Compiler (e.g., g++)
    - OpenCV 4.0 or higher
2. **Installation**:
    - **Clone the repository**:
    ``` bash
    git clone https://github.com/TitikshaBansal/ImageEditor.git
    ```
    - **Navigate to the project directory**:
    ``` bash
    cd ImageEditor
    ```
    - **Compile the code**:
    ``` bash
    g++ -o ImageEditor main.cpp image_processing.cpp utilities.cpp `pkg-config --cflags --libs opencv4` 
    ```
    - **Usage**:
    Run the Executable:
    ``` bash
    ./ImageEditor 
    ```
    Follow the on-screen instructions to perform various image editing tasks.  
    Enter appropriate values when prompted (e.g., file paths, numeric parameters).  
    Close image windows after each operation to proceed with the next task.  

## Contributing
Contributions are welcome! If you have any suggestions, improvements, or feature requests,  feel free to:
- Fork the repository.
- Create a new branch for your feature or bug fix.
- Open an issue.
- Submit a pull request.

## Licensing
This project is licensed under the MIT License. See the [LICENSE](https://github.com/TitikshaBansal/ImageEditor/blob/main/LICENSE) file for details.

## Acknowledgments
We'd like to express our gratitude to the OpenCV community and the developers who contribute to this fantastic library.

## Contact
For any questions or feedback, feel free to reach out:
- Email: titikshabansal0209@gmail.com
