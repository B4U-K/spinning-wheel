<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Spinning Prize Wheel</title>
  <style>
    body {
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
      height: 100vh;
      margin: 0;
      background: #f5f5f5;
      font-family: Arial, sans-serif;
    }

    .wheel-container {
      position: relative;
      width: 420px;
      height: 420px;
    }

    canvas {
      width: 100%;
      height: 100%;
      border-radius: 50%;
      background: white;
      box-shadow: 0 6px 18px rgba(0,0,0,0.12);
    }

    .pointer {
      position: absolute;
      top: -18px;
      left: 50%;
      transform: translateX(-50%);
      width: 0;
      height: 0;
      border-left: 18px solid transparent;
      border-right: 18px solid transparent;
      border-bottom: 28px solid red; /* default red */
      z-index: 10;
      filter: drop-shadow(0 2px 4px rgba(0,0,0,0.2));
      transition: border-bottom-color 0.3s ease;
    }

    .pointer.winner {
      border-bottom-color: green; /* turns green when spin ends */
    }

    .center-box {
      position: absolute;
      top: 50%;
      left: 50%;
      transform: translate(-50%, -50%);
      width: 120px;
      height: 120px;
      border-radius: 50%;
      background: #008000; /* green background */
      display: flex;
      justify-content: center;
      align-items: center;
      box-shadow: 0 0 15px rgba(0,0,0,0.4);
      z-index: 5;
    }

    .center-text {
      font-size: 28px;
      font-weight: bold;
      color: #fff;
      animation: glow 1.5s infinite alternate;
    }

    @keyframes glow {
      from {
        text-shadow: 0 0 5px #fff, 0 0 10px #ff00de, 0 0 20px #ff00de;
      }
      to {
        text-shadow: 0 0 10px #fff, 0 0 20px #00eaff, 0 0 30px #00eaff;
      }
    }

    button {
      margin-top: 26px;
      padding: 10px 20px;
      font-size: 18px;
      cursor: pointer;
      border: none;
      border-radius: 10px;
      background: #007bff;
      color: white;
    }
    button:disabled { opacity: 0.5; cursor: not-allowed; }
    button:hover:enabled { background: #0056b3; }
  </style>
</head>
<body>
  <div class="wheel-container">
    <div class="pointer" id="pointer"></div>
    <canvas id="wheel" width="420" height="420"></canvas>
    <div class="center-box">
      <span class="center-text">B4U</span>
    </div>
  </div>
  <button id="spin">Spin 🎉</button>

  <script>
    const canvas = document.getElementById('wheel');
    const ctx = canvas.getContext('2d');
    const spinBtn = document.getElementById('spin');
    const pointer = document.getElementById('pointer');

    const numSegments = 12;
    const colors = [
      '#FF6633', '#FFB399', '#FF33FF', '#FFFF99',
      '#00B3E6', '#E6B333', '#3366E6', '#999966',
      '#99FF99', '#B34D4D', '#80B300', '#809900'
    ];

    const radius = canvas.width / 2;
    const anglePerSegment = (2 * Math.PI) / numSegments;

    // Base rotation so number 1 starts at the top pointer
    const baseRotation = -Math.PI / 2 - anglePerSegment / 2;

    function drawWheel() {
      for (let i = 0; i < numSegments; i++) {
        const startAngle = i * anglePerSegment;
        const endAngle = startAngle + anglePerSegment;

        ctx.beginPath();
        ctx.moveTo(radius, radius);
        ctx.arc(radius, radius, radius, startAngle, endAngle);
        ctx.closePath();
        ctx.fillStyle = colors[i % colors.length];
        ctx.fill();
        ctx.strokeStyle = '#ffffff';
        ctx.lineWidth = 1;
        ctx.stroke();

        ctx.save();
        ctx.translate(radius, radius);
        ctx.rotate(startAngle + anglePerSegment / 2);
        ctx.textAlign = 'right';
        ctx.fillStyle = '#000';
        ctx.font = 'bold 18px Arial';
        ctx.fillText(String(i + 1), radius - 12, 8);
        ctx.restore();
      }
    }

    function initialDraw() {
      ctx.clearRect(0, 0, canvas.width, canvas.height);
      ctx.save();
      ctx.translate(radius, radius);
      ctx.rotate(baseRotation);
      ctx.translate(-radius, -radius);
      drawWheel();
      ctx.restore();
    }

    initialDraw();

    let spinning = false;
    let spinAngle = 0;
    let spinVelocity = 0;

    function animateSpin() {
      if (!spinning) return;

      spinAngle += spinVelocity;
      spinVelocity *= 0.992;

      if (Math.abs(spinVelocity) < 0.001) {
        spinning = false;
        spinVelocity = 0;
        spinBtn.disabled = false;

        // Turn pointer green when stopped
        pointer.classList.add('winner');

        const pointerAngle = -Math.PI / 2;
        const totalRotation = (spinAngle + baseRotation) % (2 * Math.PI);
        let local = pointerAngle - totalRotation;
        local = (local % (2 * Math.PI) + 2 * Math.PI) % (2 * Math.PI);
        const winningIndex = Math.floor(local / anglePerSegment);

        alert('Winning Number: ' + (winningIndex + 1));
        return;
      }

      ctx.clearRect(0, 0, canvas.width, canvas.height);
      ctx.save();
      ctx.translate(radius, radius);
      ctx.rotate(spinAngle + baseRotation);
      ctx.translate(-radius, -radius);
      drawWheel();
      ctx.restore();

      requestAnimationFrame(animateSpin);
    }

    spinBtn.addEventListener('click', () => {
      if (spinning) return;
      spinning = true;
      spinBtn.disabled = true;

      // Reset pointer to red at start
      pointer.classList.remove('winner');

      const extraSpins = Math.floor(Math.random() * 4) + 4; 
      const randomSpeed = (Math.PI * 2 * extraSpins) / 60;
      spinVelocity = randomSpeed + (Math.random() * 0.4 + 0.2);

      requestAnimationFrame(animateSpin);
    });
  </script>
</body>
</html>

