#include <Arduino.h>

#include <M5Core2.h>

void setup() {
  M5.begin();
    // Clear display
  M5.Lcd.clear();
  M5.lcd.setRotation(3);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Lcd.drawString("SAFECAST", 230, 215, 1);
  M5.Lcd.setTextColor(TFT_ORANGE, TFT_BLACK);
  M5.Lcd.drawString("2022", 285, 215, 1);

  M5.Lcd.setTextColor(TFT_YELLOW, TFT_BLACK);
  M5.Lcd.drawString("Menu", 50, 10, 2); // Button A
  M5.Lcd.drawString("Mode", 145, 10, 2); // Button B
  M5.Lcd.drawString("QR", 250, 10, 2); // Button C



  M5.Lcd.setTextSize(2);  //Set the font size.  设置字体大小为2
  M5.Lcd.setCursor (0,60);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Lcd.println("TF card initialized.");

 // Setup buttons
  M5.begin();  //Init M5Core.  初始化 M5Core2
  M5.Lcd.setTextColor(WHITE);


  if (!SD.begin()) {  // Initialize the SD card. 初始化SD卡
    M5.Lcd.println(
        "Card failed, or not present");  // Print a message if the SD card
                                         // initialization fails or if the
                                         // SD card does not exist
    // 如果SD卡初始化失败或者SD卡不存在，则打印消息
    while (1)
      ;
  }


  if (SD.exists("/hello.txt")) {  // Check if the "/hello.txt" file
                                  // exists.查看是否存在"/hello.txt"文件
    M5.Lcd.println("hello.txt exists.");
  } else {
    M5.Lcd.println("hello.txt doesn't exist.");
  }
  M5.Lcd.println("Creating hello.txt");
  File myFile = SD.open("/hello.txt",
                        FILE_WRITE);  // Create a new file "/hello.txt".
                                      // 创建一个新文件"/hello.txt"
  if (myFile) {                       // If the file is open, then write to it.
    M5.Lcd.println("Writing to test.txt...");
    myFile.println("SD test.");
    myFile.close();  // Close the file. 关闭文件
    M5.Lcd.println("done.");
  } else {
    M5.Lcd.println("error opening test.txt");
  }
  delay(500);
  myFile = SD.open("/hello.txt",
                   FILE_READ);  // Open the file "/hello.txt" in read mode.
                                // 以读取模式打开文件"/hello.txt"
  if (myFile) {
    M5.Lcd.println("/hello.txt Content:");
    while (myFile.available()) {
      M5.Lcd.write(myFile.read());
    }
    myFile.close();
  } else {
    M5.Lcd.println("error opening /hello.txt");  // If the file is not open.
  }
  M5.Lcd.setCursor(10, 200); //Move the cursor position to (x, y).  移动光标位置到 (x, y)处

}

void loop() {
  
  M5.update(); //Read the press state of the key.  读取按键 A, B, C 的状态
  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    M5.Lcd.print('A');
  } else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) {
    M5.Lcd.print('B');
  } else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) {
    M5.Lcd.print('C');
  } else if (M5.BtnB.wasReleasefor(700)) {
    M5.Lcd.clear(WHITE);  // Clear the screen and set white to the background color.  清空屏幕并将白色设置为底色
    M5.Lcd.setCursor(0, 0);
  }

}