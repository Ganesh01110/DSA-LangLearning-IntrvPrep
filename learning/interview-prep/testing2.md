# Quality Assurance (QA) & Testing Mastery Guide

This guide is structured to help you master QA concepts, tools, and practices for a top-tier resume. Use this to prepare for interviews so that you can confidently explain the "Why," "How," and "What" of every concept.

---

## 1. Fundamentals & Life Cycles

### 1.1 Software Development Life Cycle (SDLC)
* **What it is:** The end-to-end standard process used by software teams to plan, design, build, test, and deploy software.
* **Phases:** 
  1. Requirement Analysis 
  2. Design 
  3. Implementation / Coding 
  4. **Testing** 
  5. Deployment 
  6. Maintenance
* **Why it matters:** It provides a structured approach, ensuring that high-quality software is delivered on time.

### 1.2 Software Testing Life Cycle (STLC)
* **What it is:** A sequence of testing activities performed during the testing phase of the SDLC.
* **Phases:**
  1. Requirement Analysis (QA verifies if requirements are testable)
  2. Test Planning (Strategy, resources, scheduling)
  3. Test Case Development (Writing steps and expected results)
  4. Environment Setup (Setting up DBs, servers)
  5. Test Execution (Running the tests and reporting bugs)
  6. Test Cycle Closure (Metrics, reporting, retro)
* **Example / Interview Answer:** "Unlike SDLC where the focus is building the product, STLC is purely about verifying and validating the product. Testing is not a single action; it is an entire lifecycle."

### 1.3 Bug Life Cycle
* **What it is:** The journey of a defect from the moment it is found until it is resolved and closed.
* **Workflow:**
  * **New:** Tester finds a defect and logs it.
  * **Assigned:** QA Lead assigns it to a Developer.
  * **Open:** Developer starts investigating the bug.
  * **Fixed:** Developer fixes the code and pushes it.
  * **Pending Retest:** Waiting for QA to verify the fix.
  * **Retest / Verified:** Tester checks the defect. If the fix works, it's marked **Closed**.
  * *(Alternative routes)*: **Reopened** (if the fix didn't work), **Duplicate**, **Deferred** (fix it later), or **Rejected** (not a bug).

### 1.4 Severity vs. Priority (Classic Interview Question)
* **Severity** (Determined by QA): How much does this bug affect the functionality of the system? (Low, Minor, Major, Critical).
* **Priority** (Determined by PM/Business): How urgently does this bug need to be fixed? (Low, Medium, High).
* **Examples:**
  * **High Severity & High Priority:** The checkout button on an e-commerce site crashes the app.
  * **High Severity & Low Priority:** The app crashes when clicking an obscure, hidden deep link that 99% of customers never visit.
  * **Low Severity & High Priority:** The company's logo on the homepage is misspelled (terrible for brand reputation, but doesn't break code).
  * **Low Severity & Low Priority:** A slight color misalignment in the footer text.

---

## 2. Test Design Techniques (VERY IMPORTANT)
These techniques help QA engineers reduce the number of test cases while maximizing coverage.

### 2.1 Equivalence Partitioning (EP)
* **What it is:** Dividing input values into valid and invalid partitions. If one value in a partition works, we assume all will work.
* **How:** Instead of testing every single number, you pick one number from each group.
* **Example:** Password length must be 6-10 characters. 
  * Invalid partition 1: 1 to 5 chars (test with `3`).
  * Valid partition: 6 to 10 chars (test with `8`).
  * Invalid partition 2: > 10 chars (test with `12`).
* **Why:** Saves time. You don't need to test 6,7,8,9, and 10 separately.

### 2.2 Boundary Value Analysis (BVA)
* **What it is:** Testing the exact edges of input partitions because developers frequently make off-by-one errors (using `<` instead of `<=`).
* **How:** Test the boundaries: exactly on the boundary, just below, and just above.
* **Example:** Input age must be 18 to 60.
  * Test: `17` (Invalid), `18` (Valid min edge), `19` (Valid)
  * Test: `59` (Valid), `60` (Valid max edge), `61` (Invalid).

### 2.3 Decision Table Testing
* **What it is:** Used to test complex software logic involving multiple conditions. You create a simple table of inputs and expected outputs.
* **Example:** E-commerce discount. 
  * Rule: 20% off if you are a "New User" AND use promo code "WELCOME".
  * Logic Table: 
    * F + F -> No discount
    * T + F -> No discount
    * F + T -> Error, invalid for old users
    * T + T -> 20% off

### 2.4 State Transition Testing
* **What it is:** Used when a system moves between different states depending on user input/events.
* **Example:** ATM Pin Input.
  * Event 1 (Wrong PIN) -> State: 1st warning.
  * Event 2 (Wrong PIN) -> State: 2nd warning.
  * Event 3 (Wrong PIN) -> State: Card Blocked.

---

## 3. Bug Tracking Tool: Jira (MANDATORY)

Jira is the industry standard for agile project management and issue tracking.

* **Bug Creation Process (How to do it):**
  1. Click "Create" in Jira. Set issue type to **Bug**.
  2. **Summary:** Clear, concise title (e.g., "Login page crashes when submitting empty password").
  3. **Description/Steps to Reproduce:**
     1. Navigate to the login page.
     2. Enter correct username.
     3. Leave password field blank.
     4. Click "Submit".
  4. **Expected Result:** A UI error saying "Password cannot be empty".
  5. **Actual Result:** A 500 Internal Server error occurs and screen goes white.
  6. **Environment:** Chrome v115, Windows 11, Staging branch.
  7. **Attachments:** Attach a short video or screenshot.
* **Workflow:** Transition the bug ticket from "To Do" -> "In Progress" -> "In QA" -> "Done".

---

## 4. API Testing (ADVANCED LEVEL)

Manual UI testing only gets you so far. Validating the "brain" of the app (the backend) makes you highly valuable.

### 4.1 Key API Testing Concepts
* **Auth Tokens (JWT Testing):** APIs use JSON Web Tokens (JWT) inside an `Authorization: Bearer <token>` header. 
  * *Test idea:* Tamper with the token, send an expired token, or remove it entirely to ensure the API denies access.
* **Status Code Validation:** Ensure APIs return logically correct HTTP codes.
  * `200 OK` (Success), `201 Created` (When POSTing data)
  * `400 Bad Request` (Invalid inputs), `401 Unauthorized` (Missing/bad token), `404 Not Found`
  * `500 Internal Server Error` (Backend crashed - always a defect).
* **Schema Validation:** Verifying that the JSON response structure is perfectly adhering to the database/contract (e.g., `id` is an integer, `emails` is an array of strings).
* **Negative Testing:** Sending broken data (like strings instead of numbers, or removing mandatory payload fields) to ensure the API doesn't break, but rather responds gracefully with a `400 Bad Request`.

### 4.2 API Tools Framework
* **Swagger:** Standard documentation UI where developers document how the API works. You get the payload formats and endpoint URLs from here.
* **Postman:** The sandbox for executing HTTP requests against endpoints.
* **Postman Collection Runner:** A tool inside Postman that lets you run hundreds of requests sequentially.
* **Newman (CLI):** Command-line tool for Postman. Instead of clicking buttons, you run `newman run collection.json` in your terminal. This is widely used in SDET CI/CD pipelines.

---

## 5. Automation: Selenium & Jest (FIRE 🔥)

Automation upgrades you from purely "QA" to an "SDET" (Software Development Engineer in Test). 

### 5.1 Selenium Basics
* **What it is:** A browser automation framework. It literally opens an invisible (or visible) Chrome browser and tests UI components quickly.
* **Locators:** How Selenium identifies what element it should touch on the screen.
  * Standard locators: By `ID`, by `Name`, by `Class`.
  * Advanced locators: `XPath` (navigating the HTML tree layout) and `CSS Selectors`.
* **Actions (Forms / Clicks):**
  * `driver.findElement(By.id("email")).sendKeys("test@email.com");` (Typing)
  * `driver.findElement(By.id("login-btn")).click();` (Clicking)
* **Assertions (TestNG / JUnit):** Assertions are the "pass/fail" judge.
  * Example: `Assert.assertEquals(actualPageTitle, "Dashboard")`. If it isn't "Dashboard", the test fails.

### 5.2 Jest (Unit Testing)
* **What it is:** A highly popular JavaScript testing framework, primarily used by developers to unit-test their code. Knowing Jest proves you understand JS logic.

---

## 6. Performance & Security Awareness

### 6.1 Basic Performance Testing (JMeter)
* **What it is:** Testing how fast the system is, and how many users it can handle before crashing.
* **Load Testing:** You use **JMeter** to simulate hitting an API endpoint with 500 concurrent virtual users. You measure the *Response Time* and check if the database crashes.

### 6.2 Security Testing Awareness (OWASP & Snyk)
* **OWASP Top 10:** The global standard list of the top 10 worst web vulnerabilities. As QA, you should look out for basic ones like *SQL Injection* (typing `' OR 1=1 --` into a login box) or *XSS Cross-Site Scripting* (typing JavaScript tags `<script>alert('hack')</script>` into a comment box).
* **Snyk:** A tool that analyzes application code bases for vulnerable open-source dependencies.

---

## 7. Adding QA Projects to Your Resume

Here is how you apply the above knowledge into your resume:

### 🔥 Project 1: Comprehensive Hospital System Test Suite (Mandatory)
* **What you do:** Take your hospital management project. Write a detailed Excel sheet / document containing test cases (employing Equivalence Partitioning & BVA on patient age/IDs). Create bug reports in Jira.
* **Outcome:** You prove you can handle manual QA, Test design, STLC, and Jira.

### 🔥 Project 2: Selenium Login & Form Automation (Optional but Powerful)
* **What you do:** Write a small Java/Python script using Selenium that automatically logs into your hospital system and attempts to book an appointment. 
* **Outcome:** You prove you possess SDET fundamentals like Locators and Assertions.

### 🔥 Project 3: Zero-Touch API Testing Framework (Advanced Edge)
* **What you do:** Take the Hospital system's backend API. Create a Swagger/Postman collection for it. Write JavaScript test scripts inside Postman to validate status codes and schemas. Lastly, export it and run it using the Newman CLI.
* **Outcome:** Showcases advanced logic. You can talk about Negative Testing, JWT Authorization tokens, and Postman automations.

---
**Your Final Stack:** `Manual Testing`, `Test Design (EP, BVA)`, `STLC`, `Jira`, `API Testing (Postman/Newman)`, `Selenium`, `Performance (JMeter)`, `Security (OWASP)`.
