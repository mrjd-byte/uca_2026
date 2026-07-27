self.onmessage = async function () {
    try {
        const response = await fetch("https://dummyapi.com/users");

        if (!response.ok) {
            throw new Error("Failed to fetch users");
        }

        const users = await response.json();

        if (!users || users.length === 0) {
            self.postMessage([]);
            return;
        }

        self.postMessage(users);
    } catch (error) {
        self.postMessage({ error: "No users found" });
    }
};
