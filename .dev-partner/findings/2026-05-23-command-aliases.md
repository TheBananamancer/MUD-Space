---
title: Adding command aliases improves usability
date: 2026-05-23
tags: [usability, commands]
type: technique
project: DapperBanana/MUD-Space
---

Adding `n`, `s`, `e`, `w` as aliases for `north`, `south`, `east`, `west` movement commands significantly improves usability. Players generally expect short, single-letter commands for common actions like movement.  This small addition can make the game feel much more responsive and user-friendly.  Ensure that the CommandParser is extensible enough to easily add more aliases in the future as needed.
