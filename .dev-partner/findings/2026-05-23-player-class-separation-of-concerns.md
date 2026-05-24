---
title: Introduce Player class to separate character state
date: 2026-05-23
tags: [design, class, separation-of-concerns]
type: pattern
project: DapperBanana/MUD-Space
---

Introducing a `Player` class to encapsulate the character's state (location, inventory, etc.) is a good move.  This cleanly separates the player's data from the `Session` (which manages the connection) and the `World` (which manages the environment).  This separation makes the code more modular, testable, and easier to extend with new player-related features in the future.  It avoids the `Session` class becoming bloated with player-specific logic.
