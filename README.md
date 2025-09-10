# 🔐 OTP Based Door Lock System (Arduino + Keypad + LCD + LEDs)

This project is an **Arduino-based OTP authentication system** that simulates a smart door lock.  
The system uses a **keypad** for input, **LCD** for display, and **LEDs + buzzer** to indicate correct or incorrect OTP.  

---

## 🚀 Features
- Generates a 6-digit OTP with a button press  
- OTP displayed on LCD  
- Keypad input for OTP entry  
- ✅ Green LED → Correct OTP  
- ❌ Red LED + Buzzer → Wrong OTP  
- Clear OTP with `C` key  
- Backspace option with `*` key  

---

## 🛠️ Tech Stack
- **Hardware:** Arduino UNO, 4x4 Keypad, 16x2 I2C LCD, LEDs, Buzzer  
- **Software:** Arduino IDE (C++)  

---

## 📚 Libraries Used
- `Keypad.h` → Handle keypad inputs  
- `LiquidCrystal_I2C.h` → Control LCD over I2C  
- `Wire.h` → I2C communication  

---

## ⚙️ Working
1. Press **B** → System generates a random 6-digit OTP and shows on LCD.  
2. Enter OTP using keypad.  
3. Press **A** → System validates OTP:  
   - ✅ Correct OTP → Green LED ON  
   - ❌ Wrong OTP → Red LED + Buzzer ON  
4. Press **C** → Clear entered OTP.  
5. Press `*` → Backspace (delete last digit).  

---

## 📂 Setup Instructions
1. Connect LCD (I2C) → SDA → A4, SCL → A5.  
2. Connect LEDs & Buzzer → Pin 10, 11, 12.  
3. Connect 4x4 keypad → Pins 2–9.  
4. Open `OTP_Door_Lock_System.ino` in **Arduino IDE**.  
5. Upload to Arduino UNO.  

---

## 👨‍💻 Author
- [vashitva-chaurasia](https://www.linkedin.com/in/)
