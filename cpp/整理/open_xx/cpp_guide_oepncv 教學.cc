if // namedWindow // 創建一個窗口
{
    // namedWindow
    // Creates a window.

    void namedWindow(const String &winname, int flags = WINDOW_AUTOSIZE);

    // CV_WINDOW_NORMAL or CV_WINDOW_AUTOSIZE: CV_WINDOW_NORMAL enables you to resize the window, whereas CV_WINDOW_AUTOSIZE adjusts automatically the window size to fit the displayed image (see imshow() ), and you cannot change the window size manually.
    // CV_WINDOW_FREERATIO or CV_WINDOW_KEEPRATIO: CV_WINDOW_FREERATIO adjusts the image with no respect to its ratio, whereas CV_WINDOW_KEEPRATIO keeps the image ratio.
    // CV_GUI_NORMAL or CV_GUI_EXPANDED: CV_GUI_NORMAL is the old way to draw the window without statusbar and toolbar, whereas CV_GUI_EXPANDED is a new enhanced GUI.

    // CV_WINDOW_NORMAL或CV_WINDOW_AUTOSIZE： CV_WINDOW_NORMAL 使您可以調整窗口大小，而 CV_WINDOW_AUTOSIZE 會 自動調整窗口大小以適合顯示的圖像（請參閱 imshow（）），並且您無法手動更改窗口大小。
    // CV_WINDOW_FREERATIO或CV_WINDOW_KEEPRATIO： CV_WINDOW_FREERATIO 調整圖像而不考慮其比例，而 CV_WINDOW_KEEPRATIO 保持圖像比例。
    // CV_GUI_NORMAL或CV_GUI_EXPANDED： CV_GUI_NORMAL 是繪製沒有狀態欄和工具欄的窗口的舊方法，而 CV_GUI_EXPANDED 是一個新的增強GUI。
}

if // setWindowProperty // 動態更改窗口的參數
{
    // setWindowProperty - Changes parameters of a window dynamically.
    void setWindowProperty(const string &winname, int prop_id, double prop_value);

    // Parameters:

    // name – Name of the window.

    // prop_id – Window property to edit. The following operation flags are available:
    // CV_WND_PROP_FULLSCREEN Change if the window is fullscreen ( CV_WINDOW_NORMAL or CV_WINDOW_FULLSCREEN ).
    // CV_WND_PROP_AUTOSIZE Change if the window is resizable (CV_WINDOW_NORMAL or CV_WINDOW_AUTOSIZE ).
    // CV_WND_PROP_ASPECTRATIO Change if the aspect ratio of the image is preserved ( CV_WINDOW_FREERATIO or CV_WINDOW_KEEPRATIO ).

    // prop_value – New value of the window property. The following operation flags are available:
    // CV_WINDOW_NORMAL Change the window to normal size or make the window resizable.
    // CV_WINDOW_AUTOSIZE Constrain the size by the displayed image. The window is not resizable.
    // CV_WINDOW_FULLSCREEN Change the window to fullscreen.
    // CV_WINDOW_FREERATIO Make the window resizable without any ratio constraints.
    // CV_WINDOW_KEEPRATIO Make the window resizable, but preserve the proportions of the displayed image.
}

if // resizeWindow // 將窗口大小調整為指定大小
{
    // ResizeWindow - Resizes window to the specified size
    void resizeWindow(const String &winname, int width, int height);

    cv2.resizeWindow(winname, width, height) → None;              // Python :
    void cvResizeWindow(const char *name, int width, int height); // C :

    // Parameters:
    // winname – Window name
    // width – The new window width
    // height – The new window height

    // Note
    // The specified window size is for the image area. Toolbars are not counted.
    // Only windows created without CV_WINDOW_AUTOSIZE flag can be resized.
}
if // imshow // 在指定的窗口中顯示圖像
{
    // imshow
    // Displays an image in the specified window.

    void imshow(const String＆winname，InputArray mat);

    // If the image is 8-bit unsigned, it is displayed as is.
    // If the image is 16-bit unsigned or 32-bit integer, the pixels are divided by 256. That is, the value range [0,255*256] is mapped to [0,255].
    // If the image is 32-bit floating-point, the pixel values are multiplied by 255. That is, the value range [0,1] is mapped to [0,255].

    // This function should be followed by waitKey function which displays the image for specified milliseconds.
    // Otherwise, it won’t display the image. For example, waitKey(0) will display the window infinitely until any keypress (it is suitable for image display).
    // waitKey(25) will display a frame for 25 ms, after which display will be automatically closed. (If you put it in a loop to read videos, it will display the video frame-by-frame)

    // 此函數後面應跟隨waitKey函數，該函數將圖像顯示指定的毫秒數。否則，它將不顯示圖像。
    // 例如，waitKey（0）將無限顯示窗口，直到任何按鍵（適用於圖像顯示）。
    // waitKey（25）將顯示一個25毫秒的幀，之後顯示將自動關閉。（如果你把它放在一個循環中來閱讀視頻，它將逐幀顯示視頻）
}

if // Imread()
{
    // Imread - Loads an image from a file.

    Mat imread(const String &filename, int flags = IMREAD_COLOR);

    // CV_LOAD_IMAGE_ANYDEPTH - If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.
    // CV_LOAD_IMAGE_COLOR - If set, always convert image to the color one
    // CV_LOAD_IMAGE_GRAYSCALE - If set, always convert image to the grayscale one

    // >0 Return a 3-channel color image.
    // In the current implementation the alpha channel, if any, is stripped from the output image.Use negative value if you need the alpha channel.
    // =0 Return a grayscale image.
    // <0 Return the loaded image as is (with alpha channel).

    ////////////////////////////////////////////////////////////////////////////////////////////////////

    if // ImreadModes
    {
        // Imread flags.

    public
        enum ImreadModes {
            Unchanged = -1, // If set, return the loaded image as is (with alpha channel, otherwise it gets cropped).
            GrayScale = 0,  // If set, always convert image to the single channel grayscale image.
            Color     = 1,  // If set, always convert image to the 3 channel BGR color image.
            AnyDepth  = 2,  // If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.
            AnyColor  = 4,  // If set, the image is read in any possible color format.
            LoadGdal  = 8   // If set, use the gdal driver for loading the image.
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // IMREAD_UNCHANGED
        // If set, return the loaded image as is (with alpha channel, otherwise it gets cropped).

        // IMREAD_GRAYSCALE
        // If set, always convert image to the single channel grayscale image.

        // IMREAD_COLOR
        // If set, always convert image to the 3 channel BGR color image.

        // IMREAD_ANYDEPTH
        // If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.

        // IMREAD_ANYCOLOR
        // If set, the image is read in any possible color format.

        // IMREAD_LOAD_GDAL
        // If set, use the gdal driver for loading the image.

        // IMREAD_REDUCED_GRAYSCALE_2
        // If set, always convert image to the single channel grayscale image and the image size reduced 1/2.

        // IMREAD_REDUCED_COLOR_2
        // If set, always convert image to the 3 channel BGR color image and the image size reduced 1/2.

        // IMREAD_REDUCED_GRAYSCALE_4
        // If set, always convert image to the single channel grayscale image and the image size reduced 1/4.

        // IMREAD_REDUCED_COLOR_4
        // If set, always convert image to the 3 channel BGR color image and the image size reduced 1/4.

        // IMREAD_REDUCED_GRAYSCALE_8
        // If set, always convert image to the single channel grayscale image and the image size reduced 1/8.

        // IMREAD_REDUCED_COLOR_8
        // If set, always convert image to the 3 channel BGR color image and the image size reduced 1/8.

        ////////////////////////////////////////////////////////////////////////////////////////////////////

        // IMREAD_UNCHANGED
        // 如果設置，則按原樣返回加載的圖像（使用Alpha通道，否則會被裁剪）。

        // IMREAD_GRAYSCALE
        // 如果設置，則始終將圖像轉換為單通道灰度圖像。

        // IMREAD_COLOR
        // 如果設置，請始終將圖像轉換為3通道BGR彩色圖像。

        // IMREAD_ANYDEPTH
        // 如果設置，當輸入具有相應深度時返回16位/ 32位圖像，否則將其轉換為8位。

        // IMREAD_ANYCOLOR
        // 如果設置，則以任何可能的顏色格式讀取圖像。

        // IMREAD_LOAD_GDAL
        // 如果設置，請使用gdal驅動程序加載圖像。

        // IMREAD_REDUCED_GRAYSCALE_2
        // 如果設置，則始終將圖像轉換為單通道灰度圖像，圖像尺寸減小1/2。

        // IMREAD_REDUCED_COLOR_2
        // 如果設置，請始終將圖像轉換為3通道BGR彩色圖像，並將圖像尺寸減小1/2。

        // IMREAD_REDUCED_GRAYSCALE_4
        // 如果設置，則始終將圖像轉換為單通道灰度圖像，圖像尺寸減小1/4。

        // IMREAD_REDUCED_COLOR_4
        // 如果設置，則始終將圖像轉換為3通道BGR彩色圖像，圖像尺寸減小1/4。

        // IMREAD_REDUCED_GRAYSCALE_8
        // 如果設置，則始終將圖像轉換為單通道灰度圖像，圖像尺寸減小1/8。

        // IMREAD_REDUCED_COLOR_8
        // 如果設置，則始終將圖像轉換為3通道BGR彩色圖像，圖像尺寸減小1/8。
    }
}

// destroywindow