<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>B4U Surprise</title>

  <style>
    body {
      display: flex;
      flex-direction: column;
      justify-content: center;
      align-items: center;
      height: 100vh;
      margin: 0;
      font-family: Arial, sans-serif;

      /* Salon background image */
      background: url('background.jpg') no-repeat center center fixed;
      background-size: cover;
    }

    .overlay {
      position: absolute;
      top: 0; left: 0; right: 0; bottom: 0;
      background: rgba(255, 255, 255, 0.6); /* light overlay for readability */
      z-index: -1;
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
      width: 150px;
      height: 150px;
      border-radius: 50%;
      background: #008000;
      display: flex;
      justify-content: center;
      align-items: center;
      box-shadow: 0 0 20px rgba(0,0,0,0.5), 0 0 30px #00ff88, 0 0 60px #00ff88;
      z-index: 5;
      overflow: visible;
      cursor: pointer;
      transition: transform 0.2s ease;
    }

    .center-box:hover {
      transform: translate(-50%, -50%) scale(1.05);
      box-shadow: 0 0 25px rgba(0,0,0,0.6), 0 0 40px #00ff88, 0 0 80px #00ff88;
    }

    .center-text {
      font-size: 16px;
      font-weight: bold;
      color: #fff;
      text-align: center;
      animation: glow 1.5s infinite alternate;
      padding: 10px;
    }

    @keyframes glow {
      from {
        text-shadow: 0 0 5px #fff, 0 0 10px #ff00de, 0 0 20px #ff00de;
      }
      to {
        text-shadow: 0 0 10px #fff, 0 0 20px #00eaff, 0 0 40px #00eaff;
      }
    }

    /* Star burst effect */
    .star {
      position: absolute;
      width: 12px;
      height: 12px;
      background: yellow;
      clip-path: polygon(50% 0%, 61% 35%, 98% 35%, 68% 57%, 79% 91%, 50% 70%, 21% 91%, 32% 57%, 2% 35%, 39% 35%);
      animation: burst 1s ease-out forwards;
      z-index: 20;
    }

    @keyframes burst {
      0% {
        transform: translate(0,0) scale(0.5);
        opacity: 1;
      }
      100% {
        transform: translate(var(--x), var(--y)) scale(1.5);
        opacity: 0;
      }
    }
  </style>
</head>
<body>
  <div class="overlay"></div>

  <div class="wheel-container">
    <div class="pointer" id="pointer"></div>
    <canvas id="wheel" width="420" height="420"></canvas>
    <div class="center-box" id="center-box">
      <span class="center-text" id="center-text">B4 Unisex Salon</span>
    </div>
  </div>

  <script>
    const canvas = document.getElementById('wheel');
    const ctx = canvas.getContext('2d');
    const pointer = document.getElementById('pointer');
    const centerText = document.getElementById('center-text');
    const centerBox = document.getElementById('center-box');

    const numSegments = 12;
    const colors = [
      '#FF6633', '#FFB399', '#FF33FF', '#FFFF99',
      '#00B3E6', '#E6B333', '#3366E6', '#999966',
      '#99FF99', '#B34D4D', '#80B300', '#809900'
    ];

    const discounts = {
      1: "30%",
      2: "15%",
      3: "20%",
      4: "10%",
      5: "25%",
      6: "5%",
      7: "30%",
      8: "15%",
      9: "20%",
      10: "10%",
      11: "25%",
      12: "5%"
    };

    const radius = canvas.width / 2;
    const anglePerSegment = (2 * Math.PI) / numSegments;
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

    function createStars() {
      for (let i = 0; i < 10; i++) {
        const star = document.createElement('div');
        star.className = 'star';
        const angle = Math.random() * 2 * Math.PI;
        const distance = 80 + Math.random() * 40;
        star.style.setProperty('--x', `${Math.cos(angle) * distance}px`);
        star.style.setProperty('--y', `${Math.sin(angle) * distance}px`);
        centerBox.appendChild(star);
        setTimeout(() => star.remove(), 1000);
      }
    }

    function animateSpin() {
      if (!spinning) return;

      spinAngle += spinVelocity;
      spinVelocity *= 0.992;

      if (Math.abs(spinVelocity) < 0.001) {
        spinning = false;
        spinVelocity = 0;

        pointer.classList.add('winner');

        const pointerAngle = -Math.PI / 2;
        const totalRotation = (spinAngle + baseRotation) % (2 * Math.PI);
        let local = pointerAngle - totalRotation;
        local = (local % (2 * Math.PI) + 2 * Math.PI) % (2 * Math.PI);
        const winningIndex = Math.floor(local / anglePerSegment) + 1;

        const discount = discounts[winningIndex] || "0%";
        centerText.innerText = `You Won: ${winningIndex} (${discount} Discount) 🎉`;

        createStars();
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

    centerBox.addEventListener('click', () => {
      if (spinning) return;
      spinning = true;
      pointer.classList.remove('winner');
      centerText.innerText = 'B4 Unisex Salon';

      const extraSpins = Math.floor(Math.random() * 4) + 4; 
      const randomSpeed = (Math.PI * 2 * extraSpins) / 60;
      spinVelocity = randomSpeed + (Math.random() * 0.4 + 0.2);

      requestAnimationFrame(animateSpin);
    });
  </script>
</body>
</html>

