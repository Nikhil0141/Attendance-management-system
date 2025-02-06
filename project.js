/* script.js */
function adminLogin() {
    let password = prompt("Enter Admin Password:");
    if (password === "1234") {
        window.location.href = "admin.html";
    } else {
        alert("Incorrect Password!");
    }
}

function studentView() {
    window.location.href = "student.html";
}

function addStudent() {
    let name = prompt("Enter Student Name:");
    let rollNo = prompt("Enter Roll Number:");
    let grade = prompt("Enter Grade:");
    alert("Student Added Successfully!");
}

function markAttendance() {
    let rollNo = prompt("Enter Roll Number:");
    alert("Attendance Marked Successfully!");
}

function checkAttendance() {
    let rollNo = document.getElementById("rollNo").value;
    document.getElementById("attendanceResult").innerText = "Attendance Status: Present";
}  