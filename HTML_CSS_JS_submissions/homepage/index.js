const header = document.querySelector("header");
const btnMenu = document.querySelector(".navbar-toggler");
const form = document.querySelector("form");
const currentUrl = window.location.href;
const menuLinks = document.querySelectorAll(".navbar-nav .nav-item a");

handleClassScroll();

menuLinks.forEach((link) => {
  link.parentNode.classList.remove("active");
  if (currentUrl.includes(link.href)) {
    link.parentNode.classList.add("active");
  }
});

window.addEventListener("scroll", function () {
  handleClassScroll();
});

btnMenu.addEventListener("click", function () {
  btnMenu.classList.toggle("menuActive");
  handleClassScroll();
});

form?.addEventListener("submit", function (e) {
  e.preventDefault();
  let email_valid =
    "^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$";

  const regex = new RegExp(email_valid);

  const email = document.querySelector('form input[type="email"]').value;

  if (!regex.test(email)) {
    alert("Enter a valid email address");
    email.focus();
    return;
  } else {
    alert("Ok!");
  }

  console.log(email);
});

function handleClassScroll() {
  if (window.scrollY === 0 && !btnMenu.classList.contains("menuActive")) {
    header.classList.remove("scroll");
  } else {
    header.classList.add("scroll");
  }
}
