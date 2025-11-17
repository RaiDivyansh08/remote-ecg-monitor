

\*\*📡 Remote ECG Monitoring System (ESP32 + AD8232)\*\*



Real-time ECG waveform monitoring using an ESP32 and AD8232 ECG sensor.

The ESP32 samples ECG signal at 250 Hz and streams the data via WebSockets to a clean, modern web UI for live visualization.



---



\## 🚀 \*\*Features\*\*



\* Live ECG graph (real-time 250Hz sampling)

\* WebSocket-based data streaming

\* Clean \& responsive UI using Chart.js

\* Works on any phone/PC on same Wi-Fi

\* Minimal \& fast firmware

\* Optional static IP configuration

\* Open-source project structure



---



\## 🧠 \*\*Tech Stack Used\*\*



| Component       | Technology                             |

| --------------- | -------------------------------------- |

| Microcontroller | \*\*ESP32\*\* (Wi-Fi + ADC)                |

| Sensor          | \*\*AD8232 ECG Module\*\*                  |

| Firmware        | \*\*Arduino (C++)\*\*                      |

| Web UI          | \*\*HTML + CSS + JavaScript + Chart.js\*\* |

| Communication   | \*\*WebSockets (ws://)\*\*                 |

| Hosting         | \*\*GitHub Pages\*\*                       |



---



\## 🔌 \*\*Hardware Connections\*\*



| AD8232 Pin | ESP32 Pin   |

| ---------- | ----------- |

| \*\*OUTPUT\*\* | GPIO \*\*34\*\* |

| \*\*3.3V\*\*   | 3.3V        |

| \*\*GND\*\*    | GND         |



> Wear electrodes properly: \*\*RA\*\*, \*\*LA\*\*, \*\*RL\*\* for clean ECG waveform.



---



\## 📁 \*\*Project Structure\*\*



```

remote-ecg-monitor/

│

├── firmware/

│   └── esp32\_ecg.ino       # ESP32 firmware

│

├── web/

│   └── index.html          # Local UI (testable)

│

├── docs/

│   └── index.html          # GitHub Pages hosted UI

│

├── LICENSE

├── .gitignore

└── README.md

```



---



\## ⚙️ \*\*Firmware Setup\*\*



Open `firmware/esp32\_ecg.ino` in Arduino IDE and update:



```cpp

const char\* ssid = "YOUR\_WIFI\_NAME";

const char\* password = "YOUR\_WIFI\_PASSWORD";

```



Optional static IP (uncomment in code):



```cpp

IPAddress local\_IP(192,168,1,50);

IPAddress gateway(192,168,1,1);

IPAddress subnet(255,255,255,0);

```



---



\## 📡 \*\*How It Works\*\*



1\. ESP32 connects to Wi-Fi

2\. Starts WebSocket server on port \*\*81\*\*

3\. Reads AD8232 analog values at \*\*250 Hz\*\*

4\. Sends values to browser

5\. Browser plots real-time ECG waveform



---



\## 🖥️ \*\*Run the Web UI\*\*



\### \*\*Option 1 — GitHub Pages\*\*



Open (your deployed URL):



```

https://YOUR\_USERNAME.github.io/remote-ecg-monitor/

```



\### \*\*Option 2 — Local\*\*



```

open web/index.html

```



or Python server:



```

cd web

python -m http.server 8000

```



Open in browser:



```

http://localhost:8000/

```



Enter ESP32 IP → \*\*Connect\*\*



---



\## 📸 \*\*Live ECG Output\*\*



\*Add your screenshot here for better presentation.\*



---



\## 👨‍💻 \*\*Author\*\*



\*\*Divyansh Rai\*\*

ESP32 Developer • Full-Stack Web Developer • IoT Engineer



---



\## 📝 \*\*License\*\*



This project is licensed under the \*\*MIT License\*\*.



---



\# Want me to add a section like:



✔ Installation Steps

✔ Troubleshooting

✔ Future Improvements

✔ Screenshots

✔ Block Diagram (ASCII)

✔ Usage Guide





