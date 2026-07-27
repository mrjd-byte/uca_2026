const usersDiv = document.getElementById("users");

const worker = new Worker("worker.js");

worker.postMessage("fetchUsers");

worker.onmessage = function (event) {
    const data = event.data;

    if (data.error) {
        usersDiv.innerHTML = data.error;
        return;
    }

    if (!data.length) {
        usersDiv.innerHTML = "No users found";
        return;
    }

    usersDiv.innerHTML = data
        .map(user => `${user.name} - ${user.active ? "Active" : "Inactive"}`)
        .join("<br>");
};

worker.onerror = function () {
    usersDiv.innerHTML = "Failed to load users.";
};
