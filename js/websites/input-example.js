function answer() {
    let name = document.getElementById("name").value;
    let year = document.getElementById("year").value;

    let currentDate = new Date();
    let currentYear = currentDate.getFullYear();

    let age = currentYear - year;

    document.getElementById("result").innerText = 
      "Hello " + name + ". You are " + age + " old.";
}
