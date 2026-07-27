// worker.js
self.onmessage = async function () {
    try {
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const users = await response.json();

        if (!users || users.length === 0) {
            console.log("No users returned from API");
            return;
        }

        users.forEach(user => {
            console.log(`${user.name} - ${user.active ? "Active" : "Inactive"}`);
        });
    } catch (err) {
        console.error("Error:", err.message);
    }
};
