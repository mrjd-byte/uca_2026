const worker = new Worker("worker.js");

worker.postMessage("start");

worker.onerror = function (err) {
    console.error("Worker Error:", err.message);
};
