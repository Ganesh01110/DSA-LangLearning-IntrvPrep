# Next.js Ultimate Interview Guide (React + Next 13/14+)
*This guide contains ~60 high-impact interview questions focusing on modern Next.js concepts (App Router, Server Components, SSR/SSG algorithms, caching).*

## 🔥 PRIORITY 1: The Core Rendering Strategies

### 🔹 1. Rendering Architecture
**Q1. CSR vs SSR vs SSG vs ISR**
* **CSR (Client-Side Rendering):** 
  * **What:** Browser downloads blank HTML, React loads JS, fetches data, and renders UI.
  * **When:** Dashboards, highly interactive private routes.
* **SSR (Server-Side Rendering):**
  * **What:** Server fetches data and generates HTML *on every single request*.
  * **When:** Dynamic data that changes constantly (e.g., live stock prices, personalized feeds).
* **SSG (Static Site Generation):**
  * **What:** HTML is generated *at build time* once. Same HTML served to all users.
  * **When:** Blogs, landing pages, documentation. Highest performance.
* **ISR (Incremental Static Regeneration):**
  * **What:** Rebuilds static pages in the background after a specific time interval.
  * **When:** E-commerce product pages (needs to be fast, but stock/price might update occasionally).
* **💡 Tip:** Interviewers love asking "How would you architect an e-commerce site?" Answer: SSG for landing pages, ISR for product catalogs, CSR for the cart, and SSR for the user profile.

**Q2. What is Hydration?**
* **What:** The process where React attaches event listeners to the static HTML sent by the server, making it fully interactive.
* **How:** Server sends HTML -> Client parses HTML -> Client runs JS bundle -> React hydrates the DOM.
* **Why:** Unhydrated HTML is just a static painting. Hydration gives it "life".
* **💡 Tip:** "Hydration Mismatch" errors happen when the server-rendered HTML differs from what the client expects (e.g., using `window` object in server scope).

### 🔹 2. App Router vs Pages Router & RSC
**Q3. App Router vs Pages Router**
* **What:** 
  * `Pages Router` (`/pages`): Legacy. File-based routing using `getServerSideProps` and `getStaticProps`.
  * `App Router` (`/app`): Modern (Next 13+). Uses React Server Components (RSC) by default. Data fetching is native using standard `async/await` components.
* **Why:** App Router allows nested layouts, advanced streaming, and native Server Components.

**Q4. React Server Components (RSC) vs Client Components**
* **What/How:**
  * **Server Components (Default):** Rendered exclusively on the server. Never send JS to the browser.
  * **Client Components (Requires `"use client"`):** Can run on the server (for initial SSR) but send JS to the browser to hydrate.
* **When:**
  * Use **RSC** for data fetching, backend API access, and rendering static text.
  * Use **Client** for interactivity (`onClick`, `useState`, `useEffect`), browser APIs (`window`).
* **Why:** Drastically reduces the JavaScript bundle size shipped to the client, improving load speed (TBT/LCP).
* **💡 Tip:** Keep Client components as narrow down the DOM tree as possible. Don't put `"use client"` at the root layout!

**Q5. Can a Server Component import a Client Component?**
* **What:** YES. A Server Component can render a Client Component.
* **Can a Client Component import a Server Component?** NO. You must pass the Server Component to the Client Component as `children` or a prop.

## 🔥 PRIORITY 2: Routing & Navigation

### 🔹 3. App Router Structure
**Q6. special files in the App Router**
* **What/How:** Next.js uses file conventions.
  * `page.tsx`: Unique UI for the route.
  * `layout.tsx`: Shared UI that wraps pages (persists state across navigations).
  * `loading.tsx`: Fallback UI (Suspense boundary) while data fetches.
  * `error.tsx`: Catch-all for runtime errors.
  * `not-found.tsx`: 404 UI.
  * `route.ts`: API Endpoint.

**Q7. Dynamic Routes**
* **What:** URL segments that are defined dynamically (e.g., `/blog/1`, `/blog/2`).
* **How:** Created using square brackets: `app/blog/[id]/page.tsx`.
* **When/Why:** When creating dynamic pages from database records.
* **💡 Tip:** In the `page.tsx`, you access the variable via `props.params.id`.

**Q8. Catch-All & Optional Catch-All Routes**
* **What:** Segments that match an arbitrary depth of URLs.
* **How:** `[...slug]` (matches `/shop/clothes/shirts`). Optional: `[[...slug]]`.
* **When:** Creating generalized category pages or documentation pages with deep unpredictable structures.

**Q9. Route Groups**
* **What:** Used to organize the directory structure without affecting the URL.
* **How:** Wrap a folder in parentheses: `(marketing)`.
* **Why:** Allows having multiple different Root Layouts (e.g., one layout for `(auth)` and one for `(dashboard)`).

**Q10. Parallel Routes & Intercepting Routes (Advanced)**
* **What:** 
  * **Parallel Routes (`@folder`):** Render multiple pages simultaneously in the same layout (e.g., a dashboard with `@analytics` and `@team` loading independently).
  * **Intercepting Routes (`(..)folder`):** Load a route within the current layout without losing context (e.g., clicking an image to open it in a Modal, but refreshing the page loads the full image URL).

## 🔥 PRIORITY 3: Data Fetching & Caching

### 🔹 4. Data Fetching Strategies
**Q11. Fetching in Server Components**
* **What/How:** Simply make the component `async` and use the native `fetch` API.
* *Example:* `const data = await fetch('api.com');`
* **Why:** Server components execute on the server, so it's as secure and direct as Node.js backend. No need for `getServerSideProps` anymore.

**Q12. How Next.js Caches `fetch()`**
* **What:** In Next.js 13/14, `fetch` requests are cached automatically by default on the server.
* **How:**
  * `fetch(URL, { cache: 'force-cache' })` -> SSG (Default behavior).
  * `fetch(URL, { cache: 'no-store' })` -> SSR (Dynamic, fetches on every request).
  * `fetch(URL, { next: { revalidate: 3600 } })` -> ISR (Revalidates every hour).
* **💡 Tip:** Standard Axios does NOT integrate natively with Next.js specific caching. Use `fetch`.

**Q13. On-Demand Revalidation**
* **What:** Instead of waiting for a timer (ISR), you tell Next.js to purge the cache immediately when a database record updates.
* **How:** Using `revalidateTag('collection')` or `revalidatePath('/blog')` inside a Server Action or API route.
* **Why:** Extremely powerful for CMS integrations (e.g., user publishes a post -> cache purges -> instant update for all users).

**Q14. Streaming & Suspense**
* **What:** Progressively sending HTML from the server to the client instead of waiting for the entire page's data to finish fetching.
* **How:** Wrap slow components in `<Suspense fallback={<Loader/>}>`.
* **Why:** Improves Time to First Byte (TTFB). The user sees the header immediately while the heavy database query loads the table below it.

## 🔥 PRIORITY 4: Next.js Optimizations

### 🔹 5. Core Web Vitals Optimization
**Q15. The `<Image>` Component**
* **What:** A heavily optimized replacement for the standard `<img>` tag.
* **How it works:**
  * **Lazy Loading:** Images only load when they enter the viewport.
  * **Size Optimization:** Automatically converts images to `.webp` or `.avif`.
  * **Cumulative Layout Shift (CLS) Prevention:** Requires specific `width` and `height` to hold space in the DOM before the image loads.
  * **Why:** Massively boosts website load performance.

**Q16. The `<Link>` Component**
* **What:** Replacement for `<a>` tag for internal routing.
* **Why/How:** Pre-fetches the linked route in the background when the link becomes visible on the screen. Clicking it results in near-instant SPA navigation.

**Q17. The `next/font` Module**
* **What:** Automatically optimizes and loads custom fonts/Google fonts.
* **Why:** Removes external network requests to Google Fonts, hosts the font files locally at build time, and ensures zero layout shift.

### 🔹 6. SEO & Metadata
**Q18. Server-side Metadata in App Router**
* **What:** Next.js allows injecting `<title>` and `<meta>` tags directly from Server Components.
* **How:** Export a `metadata` object or use `generateMetadata()` function.
* *Example:* `export const metadata = { title: 'Home', description: 'desc' };`
* **Why:** Crucial for robust SEO. Web crawlers (like Googlebot) easily read server-generated meta tags.

**Q19. Dynamic SEO (generateMetadata)**
* **What/When:** When the title depends on exact data (e.g., SEO title for `/products/123`).
* **How:** `export async function generateMetadata({ params }) { const data = await fetch(id); return { title: data.name }; }`

## 🔥 PRIORITY 5: Backend Mechanics

### 🔹 7. API Routes vs Server Actions
**Q20. API Routes (Route Handlers)**
* **What:** Full backend endpoints built right into Next.js.
* **How:** Created inside `app/api/users/route.ts` exporting functions like `GET`, `POST`.
* **When:** Use when creating public APIs, webhooks, or integrating with external mobile apps.

**Q21. Server Actions (The Modern Approach)**
* **What:** Asynchronous functions executed on the server, called directly from Client or Server components without manually fetching a generic API route.
* **How:** Defined with `"use server";` at the top of an async function.
* **When:** Handling form submissions and database mutations.
* **Why/💡 Tip:** Drastically reduces boilerplate. Replaces the need to write `fetch('/api/submit')`, handles loading states elegantly via `useFormStatus`.

**Q22. Middleware in Next.js**
* **What:** Code that runs on the Edge *before* a request is completed. 
* **How:** Created using a `middleware.ts` file at the root.
* **When:** 
  * Authentication (redirecting unauthenticated users to `/login`).
  * Internationalization (i18n) (rewriting URLs based on language headers).
  * A/B Testing or Bot protection.
* **Why:** Super fast because it runs close to the user on the Edge network, preventing the underlying server from even experiencing load for rejected requests.

## 🔥 PRIORITY 6: Advanced & Vercel Specifics

### 🔹 8. State & Environment
**Q23. .env.local vs .env**
* **What:** `.env.local` overrides all other env files. Secrets should never be committed.
* **How:** Only variables prefixed with `NEXT_PUBLIC_` are exposed to the browser. Everything else is safely locked to the Node.js server environment.

**Q24. Edge Runtime vs Node.js Runtime**
* **What:** Next.js can run server functions on two environments.
* **Node.js:** Heavy standard environment. Full access to filesystem and all npm packages.
* **Edge:** Extremely fast, lightweight V8 isolates running globally. Limited APIs (no `fs`, no native Node modules). Used strictly for Middleware and fast API routes.

**Q25. React Context vs Redux in Next.js App Router**
* **What:** How to manage global state.
* **When/How:** Context and Redux are exclusively Client-side concepts. They require `"use client"`. Wrap your app in a Client Component Provider deeply inside the `layout.tsx`.
* **Interview Trap:** "Does Context ruin SEO?" Answer: No, client components are still initially HTML rendered on the server during the first pass.

### 🧠 How to Stand Out in Next.js Interviews
1. **Talk about Core Web Vitals:** Always frame your answers around User Experience metrics (LCP, CLS, TTFB, TBT). e.g., "I use the Image component specifically to avoid Cumulative Layout Shifts."
2. **Shift to RSC:** Interviewers want to know if you understand the paradigm shift to React Server Components. Emphasize how `fetch` in RSC removes the waterfall problem and minimizes client JS.
3. **Caching awareness:** Understand that the App Router caches aggressively by default. Knowing how and when to use `revalidatePath` proves you're a mid/senior-level engineer.
