# 🤝 Contributing to NetSniffer

Thanks for your interest in contributing! Since this project is in early development, contributions of all kinds are especially valuable — bug reports, ideas, code improvements, and documentation fixes all help move things forward.

---

## 📌 Ways to Contribute

- 🐛 **Report bugs** — something broken or behaving unexpectedly? Open an issue.
- 💡 **Suggest features** — have an idea for what this tool should do? Share it.
- 🔧 **Fix bugs or implement features** — pick up an open issue and submit a PR.
- 📝 **Improve documentation** — clearer docs help everyone.
- 🧪 **Test on different platforms/environments** — compatibility reports are welcome.

---

## 🚀 Getting Started

1. **Fork** the repository on GitHub
2. **Clone** your fork locally:
   ```bash
   git clone https://github.com/YOUR_USERNAME/netsniffer.git
   cd netsniffer
   ```
3. **Set up** the project following [SETUP.md](./SETUP.md)
4. **Create a branch** for your work:
   ```bash
   git checkout -b feature/your-feature-name
   # or
   git checkout -b fix/bug-description
   ```

---

## 🔄 Submitting a Pull Request

1. Make your changes on your branch
2. Test that the project still builds and runs:
   ```bash
   make clean && make
   sudo ./netsniffer -i <your-interface> -v
   ```
3. Keep commits focused and descriptive:
   ```bash
   git commit -m "feat: add TCP layer parsing"
   git commit -m "fix: resolve null deref on empty packet"
   ```
4. Push your branch:
   ```bash
   git push origin feature/your-feature-name
   ```
5. Open a **Pull Request** against the `main` branch with a clear description of what you changed and why.

---

## 🧹 Code Style Guidelines

This project is written in C/C++. Please follow these conventions:

- Use **C++17** features where appropriate
- Keep functions small and focused — one responsibility per function
- Use descriptive variable and function names
- Add comments for anything non-obvious, especially around low-level socket/packet logic
- Avoid memory leaks — free resources you allocate
- Prefer `nullptr` over `NULL`

**Formatting:**
- 4-space indentation
- Opening braces on the same line (`K&R style`)
- Keep lines under ~100 characters where possible

---

## 🐛 Reporting Bugs

When opening a bug report, please include:

- **OS and version** (e.g., Ubuntu 22.04, macOS 14)
- **GCC/G++ version** (`g++ --version`)
- **Steps to reproduce** the issue
- **Expected behavior** vs. **what actually happened**
- **Error output or logs** (use `-v` flag for verbose output)

---

## 💡 Suggesting Features

Open an issue with the `enhancement` label. Describe:

- What you'd like the tool to do
- Why it would be useful
- Any relevant context (use case, similar tools, etc.)

Since this is an early-stage project, the scope is still flexible — good ideas are very welcome.

---

## 📋 Current Priority Areas

These are areas where contributions would be especially helpful right now:

- [ ] TCP/UDP layer parsing
- [ ] DNS and HTTP protocol dissection
- [ ] Live traffic statistics (packet counts, bytes, rates)
- [ ] PCAP file export
- [ ] Cross-platform compatibility improvements
- [ ] Unit tests / test infrastructure

---

## ⚖️ License

By contributing, you agree that your contributions will be licensed under the project's [MIT License](./LICENSE).

---

Thanks again for contributing — every bit helps! 🙌
