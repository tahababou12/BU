'use client'; // Add this line

import React, { useState, useEffect } from 'react';
// import './globals.css';

export default function App() {
  const [x, setX] = useState("");
  const [y, setY] = useState("");
  const [z, setZ] = useState("");

  function handleMotionEvent(event) {
    console.log("handle motion event", event);

    var x = event.accelerationIncludingGravity.x;
    var y = event.accelerationIncludingGravity.y;
    var z = event.accelerationIncludingGravity.z;

    setX(x);
    setY(y);
    setZ(z);
  }

  useEffect(() => {
    window.addEventListener("devicemotion", handleMotionEvent, true);
  }, [x, y, z]);

  return (
    <div className="App">
      <h1>Device Motion</h1>
      <div>
        X - {x} Y - {y} Z - {z}
      </div>
    </div>
  );
}