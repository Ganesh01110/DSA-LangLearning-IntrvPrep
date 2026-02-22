# 🧪 Testing (Types & Tools)

1. **What is Unit Testing?**
    - Testing individual components or functions in isolation (e.g., using JUnit, Jest).

2. **What is Integration Testing?**
    - Testing how different modules or services work together.

3. **What is Functional Testing?**
    - Testing the application against the functional requirements (what it does).

4. **What is Regression Testing?**
    - Running existing tests after code changes to ensure no new bugs were introduced.

5. **What is Smoke Testing?**
    - Preliminary testing to reveal simple failures severe enough to reject a prospective software release.

6. **What is Sanity Testing?**
    - A subset of regression testing used to verify that specific bug fixes or changes work as expected.

7. **What is End-to-End (E2E) Testing?**
    - Testing the entire application flow from start to finish, including dependencies (e.g., using Cypress, Selenium, Playwright).

    - **Detailed Explanation**:
      - Re-running functional and non-functional tests to ensure that previously developed and tested software still performs after a change.
    - **Interview Answer**:
      - "Regression testing is 'Making sure you didn't break anything today'. Every time we add a new feature, we run our entire suite of old tests. This ensures that our new 'Dark Mode' feature didn't accidentally break the 'Checkout' button that's been working for months."
      - **Use Case**: Running your full test suite after refactoring the 'User Authentication' logic to ensure all existing login methods still work.

5. **Explain the "Test Pyramid".**
    - **Detailed Explanation**:
      - A strategy that suggests having a large number of Unit tests, some Integration tests, and very few E2E tests.
    - **Interview Answer**:
      - "The Test Pyramid is about 'Speed and Cost'. **Unit tests** are at the bottom because they are fast and cheap; you should have thousands of them. **Integration tests** are in the middle. **E2E tests** are at the top—they are slow and expensive, so you only use them for the most critical paths. This ensures you have a stable and fast testing suite."
      - **Use Case**: Writing 500 unit tests for business logic, 50 integration tests for API calls, and 5 E2E tests for the 'Core User Journey'.

6. **What is TDD (Test-Driven Development)?**
    - **Detailed Explanation**:
      - A development process where you write the test **before** the code (Red-Green-Refactor).
    - **Interview Answer**:
      - "TDD is 'Flipping the Script'. First, you write a test that fails (Red). Then, you write the minimum code to make it pass (Green). Finally, you clean up the code (Refactor). It forces you to think about the requirements and API design before you even start coding, which leads to much cleaner and more reliable software."
      - **Use Case**: Writing a test for a 'Tax Calculator' before you've even decided how to calculate the tax percentage.

7. **What is BDD (Behavior-Driven Development)?**
    - **Detailed Explanation**:
      - An extension of TDD that focuses on the **behavior** of the system from the perspective of an end-user. It uses human-readable language (Given, When, Then).
    - **Interview Answer**:
      - "BDD is 'English-language testing'. Instead of technical code, we write scenarios like: '**Given** I am on the login page, **When** I enter a valid password, **Then** I should see my profile.' This helps developers, testers, and business owners all agree on exactly how a feature should work using the same language."
      - **Use Case**: Collaborating with a Product Manager to define the 'Voucher Code' logic using Gherkin syntax.

8. **What is Mocking?**
    - **Detailed Explanation**:
      - Creating a 'Fake' version of a dependency (like an API or Database) to control its behavior during a test.
    - **Interview Answer**:
      - "Mocking is 'Using a Stunt Double'. If you're testing a function that sends an actual email, you don't want to spam your inbox every time you run a test. You create a 'Mock Email Service' that *pretends* to send the email and just tells your test: 'Yes, I was called!'. It makes tests faster, cheaper, and more predictable."
      - **Use Case**: Mocking the 'Stripe API' so you can test your 'Payment Success' screen without actually spending real money.

9. **Difference between "Stub" and "Mock"?**
    - **Detailed Explanation**:
      - **Stub**: Provides canned answers to calls made during the test.
      - **Mock**: Records which calls were made and allows you to verify that they happened correctly.
    - **Interview Answer**:
      - "A **Stub** is a 'Dummy'—it just says: 'Here is some fake data'. A **Mock** is a 'Spy'—it watches your code and verifies: 'Did you call the Save function exactly once with the correct ID?'. Stubs are for providing input; Mocks are for verifying output and behavior."
      - **Use Case**: Using a **Stub** to provide a fake user list, and a **Mock** to verify that the 'Delete' API was called when the user clicked the trash icon.

10. **What is Jest?**
    - **Detailed Explanation**:
      - A delightful JavaScript Testing Framework with a focus on simplicity. It is maintained by Meta and works out of the box for most React projects.
    - **Interview Answer**:
      - "Jest is the 'Gold Standard' for React testing. It's an all-in-one tool: it provides the test runner, the assertion library (`expect`), and the mocking tools. It’s famous for being very fast (thanks to parallel execution) and having great 'Snapshot' testing features that make UI testing easy."
      - **Use Case**: Using Jest to run all the unit tests for your 'Portfolio' components.

11. **Explain "Snapshot Testing" in Jest.**
    - **Detailed Explanation**:
      - Jest takes a 'picture' of your component's rendered output and compares it to a saved version. If they differ, the test fails.
    - **Interview Answer**:
      - "Snapshot testing is 'Spot the Difference'. The first time you run it, Jest saves the HTML output of your component to a file. Next time, it renders the component again and compares it. If you accidentally deleted a button or changed a CSS class, Jest will catch it immediately. It’s perfect for ensuring your UI doesn't 'drift' over time."
      - **Use Case**: Ensuring that your 'Project Card' always has the correct structure and class names.

12. **What is "Code Coverage"?**
    - **Detailed Explanation**:
      - A metric that shows what percentage of your source code is executed by your tests.
    - **Interview Answer**:
      - "Code Coverage is the 'Health Report' for your tests. It tells you: 'You’ve tested 80% of your code, but you completely missed the error-handling logic in lines 50-60'. While 100% coverage doesn't mean your app is bug-free, low coverage is a huge red flag that you have 'blind spots' where bugs could be hiding."
      - **Use Case**: Aiming for 90% coverage on the 'Payment Processing' module of an app.

13. **What is a "Smoke Test"?**
    - **Detailed Explanation**:
      - A quick, non-exhaustive set of tests that verify the most basic functions of an app. If they fail, the build is rejected immediately.
    - **Interview Answer**:
      - "Smoke testing is 'Checking for fire'. Before you run 2 hours of detailed tests, you run a 1-minute test to see: 'Does the app even open? Can I see the Login button?'. If the app crashes on the home page, there's no point in running the rest of the tests. It’s about catching 'catastrophic' failure early."
      - **Use Case**: Checking if the `localhost` site loads at all after a new deployment.

14. **What is "Sanity Testing"?**
    - **Detailed Explanation**:
      - Performed after receiving a software build with minor code changes or bug fixes to verify that the bugs have been fixed and no new bugs are introduced.
    - **Interview Answer**:
      - "Sanity testing is 'Targeted Verification'. If I just fixed a bug in the 'Search Result' pagination, a sanity test would check specifically the search results and pagination. It’s not a full test suite; it’s just a quick check to see if the fix actually worked and didn't break things in its immediate vicinity."
      - **Use Case**: Checking if the 'Total Price' still calculates correctly after you changed the 'Tax Rate' logic.

15. **Difference between "Manual" and "Automated" testing?**
    - **Detailed Explanation**:
      - **Manual**: Humans clicking buttons and checking outputs.
      - **Automated**: Scripts running tests and checking outputs automatically.
    - **Interview Answer**:
      - "**Manual testing** is for 'Exploration'—it’s great for UI polish, user feel, and find 'weird' bugs that a script might miss. **Automated testing** is for 'Efficiency'—it can run 1,000 tests in 5 seconds and is much more reliable for repetitive tasks. In a good team, you need both: Automation for the core stability, and Manual for the final human touch."
      - **Use Case**: Using Automation to test the API logic and Manual testing to check if the 'Animation Speed' feels right.

16. **What is Selenium?**
    - **Detailed Explanation**:
      - One of the oldest and most popular tools for automating web browsers. It supports multiple languages (Java, Python, C#, etc.).
    - **Interview Answer**:
      - "Selenium is the 'Old Reliable' of web automation. It allows you to write scripts that control a real browser cross-platform. While it can be slower and more 'flaky' than modern tools like Cypress, its support for multiple languages and every single web browser makes it a powerful choice for enterprise companies."
      - **Use Case**: Running E2E tests for a legacy bank application that must work on Internet Explorer.

17. **What is Cypress?**
    - **Detailed Explanation**:
      - A modern E2E testing framework built specifically for the modern web. It runs inside the browser and has built-in waiting and debugging tools.
    - **Interview Answer**:
      - "Cypress is the 'Developer's Choice'. Unlike Selenium, Cypress runs directly inside the same engine as your app. This means it’s much faster, less flaky, and has amazing features like 'Time Travel'—you can literally hover over any test step and see exactly what the UI looked like at that millisecond. It makes E2E testing actually fun."
      - **Use Case**: Writing E2E tests for your 'Smart Parking' dashboard.

18. **Explain "Flaky Tests".**
    - **Detailed Explanation**:
      - A test that fails and passes intermittently without any changes to the code. Usually caused by timing issues or network dependency.
    - **Interview Answer**:
      - "Flaky tests are the 'Crying Wolf' of testing. If a test fails 10% of the time for no reason, developers will start ignoring it. This is dangerous because an actual bug could hide behind that 'fake' failure. We fix flakiness by using better synchronization, avoiding hardcoded 'sleep' commands, and using isolated test data."
      - **Use Case**: Re-writing a Cypress test that fails whenever the computer's CPU is slightly slow.

19. **What is "White Box" vs "Black Box" testing?**
    - **Detailed Explanation**:
      - **White Box**: The tester knows the internal code and structure.
      - **Black Box**: The tester only knows the inputs and expected outputs (user perspective).
    - **Interview Answer**:
      - "**White Box** is testing with the 'Hood Open'—you're checking the gears and logic of the code itself. **Black Box** is testing the 'Closed Engine'—you just press the gas pedal and see if the car moves. Developers do White Box (unit tests), while QA teams or users usually do Black Box."
      - **Use Case**: A developer testing the edge cases of an algorithm (White Box) vs a Beta Tester using the app features (Black Box).

20. **What is "Exploratory Testing"?**
    - **Detailed Explanation**:
      - An informal, creative testing process where the tester explores the app without pre-defined test cases to find unexpected bugs.
    - **Interview Answer**:
      - "Exploratory testing is 'Playing around with a purpose'. You don't follow a list of steps. Instead, you think like a user trying to break the app: 'What if I click this button 10 times? What if I disconnect the internet mid-upload?'. It finds the 'unscripted' bugs that automated tests would never even look for."
      - **Use Case**: Finding out that clicking 'Back' while a modal is closing crashes the app.

21. **What is "Load Testing"?**
    - **Detailed Explanation**:
      - Testing the app's performance under expected normal and peak conditions (e.g., 100 concurrent users).
    - **Interview Answer**:
      - "Load testing is 'Checking capacity'. You simulate a group of users visiting your site at once. You want to see: 'Do the pages still load in under 2 seconds? Does the backend handle the 50 database connections comfortably?'. It helps you identify where the 'bottleneck' is before your app goes live."
      - **Use Case**: Testing if your 'PulseQueue' system handles 500 concurrent appointment bookings on a Monday morning.

22. **What is "Stress Testing"?**
    - **Detailed Explanation**:
      - Pushing the system beyond its limits to see where and how it breaks (e.g., 10,000 concurrent users).
    - **Interview Answer**:
      - "Stress testing is 'The Breaking Point'. You keep adding users until the server finally crashes. The goal isn't just to see it fail, but to see **how** it fails. Does it fail gracefully with an error page? Or does it corrupt the database and take 2 hours to restart? It’s about building 'Resilience'."
      - **Use Case**: Crashing your system with 10x traffic to see if its 'Self-Healing' mechanism restarts it properly.

23. **What is "A/B Testing"?**
    - **Detailed Explanation**:
      - Showing two versions of a page (A and B) to different segments of users to see which one performs better.
    - **Interview Answer**:
      - "A/B testing is 'Competitive Design'. You show half your users a 'Green Buy Button' and the other half a 'Blue Buy Button'. You then track which group actually buys more. It’s a data-driven way to make design and business decisions instead of just guessing what users like."
      - **Use Case**: Testing if a 'Pop-up' discount code leads to more sales than a 'Static' banner.

24. **What is "Usability Testing"?**
    - **Detailed Explanation**:
      - Testing how easy and intuitive a software product is for actual users to use.
    - **Interview Answer**:
      - "Usability testing is 'Looking through the user's eyes'. You give a person who has never seen your app a simple task (like 'Find the settings page') and just watch them. If they struggle for 2 minutes, your UI has failed. It’s the best way to find 'confusion' bugs that don't throw errors but drive users away."
      - **Use Case**: Realizing that users can't find the 'Filter' icon because it looks like a piece of paper.

25. **Explain "CI/CD Pipeline" in testing.**
    - **Detailed Explanation**:
      - Automatically running the test suite every time code is committed to ensures that bugs are caught before they reach production.
    - **Interview Answer**:
      - "The CI/CD pipeline is the 'Safety Net'. In a modern team, you don't 'choose' to run tests; the system forces it. When you push code, GitHub Actions automatically starts the 'Pipeline'. It runs your unit, integration, and even E2E tests. If even one test fails, the code cannot be merged. It guarantees a 'Minimum Level of Quality' for every single line of code added to the app."
      - **Use Case**: Blocking a merge request because it would cause the 'Unit Tests' to drop below 80% coverage.


26. **What is "Mocking" vs "Stubbing" in practice?**
    - **Detailed Explanation**:
      - **Stubbing**: Providing expected return values for specific calls (e.g., `when(service.get()).thenReturn(data)`).
      - **Mocking**: Setting expectations on calls and verifying they happened (e.g., `verify(service).save(data)`).
    - **Interview Answer**:
      - "In practice, I use **Stubbing** when my code *needs* something to continue—like a user object from a database. I use **Mocking** when I want to ensure my code *did* something—like sending an email or saving a file. Stubbing is for 'Inputs', Mocking is for 'Verifying the Action'."
      - **Use Case**: Stubbing a 'Price Service' to return $10 and then Mocking the 'Analytics Service' to see if it was notified of the sale.

27. **What is "TDD" vs "Traditional Testing"?**
    - **Detailed Explanation**:
      - **Traditional**: Write code first, then write tests to verify it works.
      - **TDD**: Write tests first, then write just enough code to pass the tests.
    - **Interview Answer**:
      - "Traditional testing is 'Verifying what I built'. TDD is 'Designing while I build'. TDD takes more discipline but results in code that is 100% testable by design. In traditional testing, you often realize at the end that your code is 'Hard to test' because it's too tightly coupled. TDD prevents that from ever happening."
      - **Use Case**: Using TDD to build a complex 'Discount Engine' to ensure every edge case is handled before the logic is finished.

28. **Explain "Shift Left" testing.**
    - **Detailed Explanation**:
      - Moving testing activities as early as possible in the software development lifecycle (to the 'left' side of the timeline).
    - **Interview Answer**:
      - "Shift Left means 'Start testing on day one'. Instead of waiting for a finished app to give to a QA team, the developers write tests for every line of code they write. This catches bugs when they are 'tiny and cheap' to fix, rather than 'huge and expensive' right before a release."
      - **Use Case**: Integrating automated linting and unit tests into the very first commit of a project.

29. **What is "API Testing"?**
    - **Detailed Explanation**:
      - Verifying that an API meets expectations for functionality, reliability, performance, and security. It usually involves tools like Postman or Supertest.
    - **Interview Answer**:
      - "API testing is testing the 'Headless' part of your app. You don't care about the UI; you just send a JSON request to an endpoint and check if you get the right JSON response and the correct HTTP status code (like 200 OK or 401 Unauthorized). It’s much faster than E2E testing but more thorough than unit testing."
      - **Use Case**: Verifying that the `/api/parking/entry` endpoint correctly calculates the remaining slots.

30. **What is a "Contract Test"?**
    - **Detailed Explanation**:
      - A way to ensure that two systems (like a Frontend and a Backend) agree on the data format they are using to communicate.
    - **Interview Answer**:
      - "Contract testing is 'Making sure we both follow the rules'. If the Backend team changes a field from `user_id` to `id`, it normally breaks the Frontend. Contract tests catch this early by verifying that the 'Contract' (the data structure) hasn't been broken by either side without the other knowing."
      - **Use Case**: Using a tool like Pact to ensure the 'Notification Service' and 'Billing Service' can still talk to each other.

31. **Explain "Component Testing" in React.**
    - **Detailed Explanation**:
      - Testing a single React component (often with React Testing Library) to ensure it renders correctly and responds to user events.
    - **Interview Answer**:
      - "Component testing is 'Functionality in isolation'. You render a single button or a form in a 'test browser' and simulate the user: 'If I click this, does the text change?'. We use **React Testing Library** because it encourages us to test based on what the user sees (like text on a button) rather than the internal code state."
      - **Use Case**: Testing a 'Login Form' to ensure it shows an error message when the user forgets to type a password.

32. **What is "Playwright"?**
    - **Detailed Explanation**:
      - A modern E2E testing framework from Microsoft. It supports all modern browsers (Chromium, Firefox, WebKit) and is extremely fast and reliable.
    - **Interview Answer**:
      - "Playwright is the 'New Powerhouse' for E2E testing. It’s similar to Cypress but can test multiple browser tabs, support WebKit (Safari), and handle difficult things like iframes and file uploads much more easily. It has an amazing 'Code Gen' tool that actually writes the test for you as you click around the site."
      - **Use Case**: Writing high-speed E2E tests that run on Chrome, Firefox, and Safari simultaneously.

33. **What is "Unit" vs "Functional" testing?**
    - **Detailed Explanation**:
      - **Unit**: Testing a single piece of code (logic).
      - **Functional**: Testing a specific feature from the user's perspective (e.g., 'Can I reset my password?').
    - **Interview Answer**:
      - "**Unit testing** checks the 'Math'—does the tax function return the right number? **Functional testing** checks the 'Feature'—can the user actually complete the tax form and Save it? One is about code correctness; the other is about user success."
      - **Use Case**: Unit testing the 'Math' behind a discount and Functional testing the 'Apply Coupon' button in the checkout.

34. **Explain "Dry" tests (Don't Repeat Yourself).**
    - **Detailed Explanation**:
      - A principle that aims to reduce the repetition of test code by using helper functions and shared setup.
    - **Interview Answer**:
      - "DRY tests mean 'Keep your test code as clean as your app code'. If you need a 'Log in as Admin' step in 50 different tests, you don't write it 50 times. You create a helper function. This makes your tests much easier to maintain—if the login URL changes, you only fix it in **one** place instead of 50."
      - **Use Case**: Creating a `sharedSetup.js` file for all your database-related integration tests.

35. **What is "Negative Testing"?**
    - **Detailed Explanation**:
      - Testing the system with invalid inputs or unexpected behavior to ensure it handles errors gracefully.
    - **Interview Answer**:
      - "Negative testing is 'Trying to break things'. You don't just test that '1+1=2'; you test: 'What if I give it a string? What if I give it a NULL? What if I try to buy -5 items?'. A good developer ensures the app says: 'Hey, that's not allowed' instead of just crashing with a cryptic error."
      - **Use Case**: Verifying that a 'Age' field on a form correctly rejects negative numbers and letters.

36. **What is "Data-Driven Testing"?**
    - **Detailed Explanation**:
      - Running the same test logic multiple times using different sets of input data from an external source (like a CSV or array).
    - **Interview Answer**:
      - "It’s 'Testing in bulk'. If you want to test a 'Search' feature, you don't write 10 tests for 'Apple', 'Banana', etc. You write one test and give it an 'Array of Words'. The test runs in a loop for every word in that array. It's an efficient way to cover many test cases with very little code."
      - **Use Case**: Testing a 'Login' function with a list of 50 common weak passwords to ensure they are all rejected.

37. **Explain "Performance Testing" vs "Load Testing".**
    - **Detailed Explanation**:
      - **Performance**: A broad term for testing speed, scalability, and stability.
      - **Load**: A specific type of performance testing that measures how the system handles a certain amount of users.
    - **Interview Answer**:
      - "**Performance testing** is a 'General checkup'—how fast is the app? **Load testing** is a 'Stress test'—how many people can it handle before it starts sweating? You do Performance testing to improve user experience, and Load testing to plan your server costs."
      - **Use Case**: Measuring the 'Page Load Time' on a 3G network (Performance) vs 500 users at once (Load).

38. **What is "Accessibility" (a11y) testing?**
    - **Detailed Explanation**:
      - Testing that your website is usable for people with disabilities (vision, hearing, motor skills).
    - **Interview Answer**:
      - "Accessibility testing is about 'Inclusion'. We use automated tools like **Lighthouse** or **axe-core** to scan our page for common issues like: 'Is there enough color contrast? Are there alt-tags on images? Is the font big enough?'. It’s not just 'nice to have'—in many industries, it's a legal requirement."
      - **Use Case**: Using a screen reader (like VoiceOver) to verify that a blind user can navigate your 'Parking' table.

39. **What is "Security Testing" (DAST/SAST)?**
    - **Detailed Explanation**:
      - **SAST**: Testing the source code for vulnerabilities without running it.
      - **DAST**: Testing the running application for vulnerabilities (like a hacker).
    - **Interview Answer**:
      - "**SAST** is like a 'Code Review' by a security expert (looking for hardcoded passwords). **DAST** is like a 'Fake Hacker' attacking your website (trying to do SQL Injection). Using both ensures that your code is safe from the inside out."
      - **Use Case**: Using 'Snyk' (SAST) to find vulnerable npm packages and 'OWASP ZAP' (DAST) to scan your live staging site.

40. **Explain "Chaos Engineering".**
    - **Detailed Explanation**:
      - The discipline of experimenting on a system in order to build confidence in its capability to withstand turbulent conditions in production.
    - **Interview Answer**:
      - "Chaos Engineering is 'Breaking things on purpose in production'. You use tools (like Netflix’s **Chaos Monkey**) to randomly shut down servers or disconnect databases to see if your app is truly 'Resilient'. If your app stays online even when half the servers are dead, you've built a truly robust system."
      - **Use Case**: Randomly killing a 'Kafka Broker' to see if the system automatically recovers without losing messages.

41. **What is "Mutation Testing"?**
    - **Detailed Explanation**:
      - A tool changes tiny things in your code (e.g., changes `>` to `<`) and checks if your tests fail. If the tests still pass, it means your tests aren't actually checking the logic.
    - **Interview Answer**:
      - "Mutation testing is 'Testing your Tests'. If I change a math operation in your code and your tests still pass, your tests are 'weak'. It helps you find 'useless' tests that have 100% code coverage but aren't actually asserting anything important."
      - **Use Case**: Using a tool like Stryker to find and fix 'lazy' tests in your Java backend.

42. **What is "Visual Regression Testing"?**
    - **Detailed Explanation**:
      - Testing that checks for visual changes in the UI by comparing screenshots pixel-by-pixel.
    - **Interview Answer**:
      - "It’s 'Pixel-perfect verification'. Instead of checking if a button *exists* (HTML), it checks if the button *looks right* (CSS). If you accidentally changed a font-size by 1px or a color by one shade, a visual regression tool (like Percy or Applitools) will highlight the difference in red."
      - **Use Case**: Ensuring a 'Tailwind CSS' update didn't accidentally shift the spacing on your header.

43. **Explain "Parallel Testing".**
    - **Detailed Explanation**:
      - Running multiple tests at the exact same time across different servers or CPU cores to save time.
    - **Interview Answer**:
      - "Parallel testing is the 'Ultimate Time-Saver'. If you have 1,000 E2E tests and they take 2 hours to run one by one, that slows the whole team down. You can split them into 10 groups and run them on 10 different servers in parallel. Now the whole suite finishes in 12 minutes. It’s essential for modern 'High-Velocity' teams."
      - **Use Case**: Configuring GitHub Actions to run your 'Backend' tests and 'Frontend' tests at the same time.

44. **What is "Headless" testing?**
    - **Detailed Explanation**:
      - Running browser-based tests without actually opening a visible browser window.
    - **Interview Answer**:
      - "Headless is testing 'In the Dark'. Browsers use a lot of RAM to draw a UI. By running 'Headless', you skip the drawing and just run the logic. It’s much faster and is the ONLY way to run browser tests in a CI/CD environment where there is no monitor or screen."
      - **Use Case**: Running your 'Cypress' tests in a Linux Cloud Runner where no desktop UI exists.

45. **What is "Unit" vs "Integration" vs "E2E" (Quick Summary)?**
    - **Detailed Explanation**:
      - **Unit**: Smallest part (Function).
      - **Integration**: Communication (API/DB).
      - **E2E**: User Journey (Browser).
    - **Interview Answer**:
      - "**Unit** ensures the math is right. **Integration** ensures the services talk to each other. **E2E** ensures the user can actually buy the product. A good app needs a lot of Units, some Integration, and a few E2E."
      - **Use Case**: Having 100 unit tests for a 'Discount' algorithm, 10 integration tests for the 'Pay' API, and 1 E2E test for the 'Complete Purchase' flow.

46. **How to handle "Time" in testing?**
    - **Detailed Explanation**:
      - Using 'Fake Timers' to control time-based events like `setTimeout` or `setInterval` without actually waiting.
    - **Interview Answer**:
      - "Never use `sleep` in a test—it’s slow and flaky. Instead, use 'Fake Timers'. You can tell the test: 'Act as if 10 seconds have passed instantly'. This lets you test a 'Token Expiration' or a 'Timed Popup' without actually sitting there waiting behind the screen."
      - **Use Case**: Testing that a 'Session Expired' message appears after 30 minutes of inactivity.

47. **What is "Mocking Global Variables" (like `window.location`)?**
    - **Detailed Explanation**:
      - Using specialized mocking tools to override built-in browser objects that are usually hard to change.
    - **Interview Answer**:
      - "Some things are hard to test because the browser 'owns' them—like the current URL. We can use Specialized libraries to 'spy on' or 'mock' these globals. This lets us test: 'If the user navigates to /success, do we show the right message?' without actually changing the page URL and breaking the test runner."
      - **Use Case**: Testing that an app correctly redirects a user to the 'Mobile App Store' if they are on an iPhone.

48. **What is "Cross-browser Testing"?**
    - **Detailed Explanation**:
      - Testing that an application works correctly across different web browsers (Chrome, Safari, Firefox, Edge).
    - **Interview Answer**:
      - "Browsers have different 'Engines'. Something that looks perfect in Chrome (Blink engine) might be broken in Safari (WebKit). Cross-browser testing ensures your site works for everyone, not just those using Google Chrome. Modern tools like Playwright make this easy by running the same test on all three major engines automatically."
      - **Use Case**: Verifying that your 'PulseQueue' dashboard layout doesn't break in Safari after adding a new 'Flexbox' feature.

49. **Explain "Test Data Management".**
    - **Detailed Explanation**:
      - The process of ensuring that tests have the correct, isolated data they need to run without interfering with each other.
    - **Interview Answer**:
      - "Test data is the 'Fuel' for your tests. You never want two tests sharing the same Database user—one test might delete it while the other is trying to edit it. We manage this by using 'Factory' patterns to create a fresh, unique user for every single test and then cleaning up the DB after the test finishes."
      - **Use Case**: Creating a unique 'Test Parking Slot' for every single test so they can run in parallel without conflicts.

50. **What is the "Philosophy" of Testing?**
    - **Detailed Explanation**:
      - Testing is not about finding bugs; it’s about providing **confidence** that the code works and is safe to change.
    - **Interview Answer**:
      - "Testing is 'Confidence as a Service'. The goal isn't to reach 100% coverage; it's to reach a point where I can change a major part of the code, run the tests, and say with 100% certainty: 'It’s safe to deploy'. Tests are a 'Gift to your future self'—they allow you to move fast and be bold without the fear of breaking things."
      - **Use Case**: Refactoring a 2-year-old 'Legacy Module' with confidence because the original tests are still passing.
