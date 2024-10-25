# libuniversesim
Library for simulations of star systems, planets, factions and their relationships, economics for my future game.

## Why?
I've been working on one game for some time now.
And I cannot fully sellte with graphics technology so far (be it Raylib, pure OpenGL or some big engine line Unity).
But I have some ideas of how game's world should look and work in a broader scale.
So I've decided to make a library for it so I can later link to any engine of my future choice.
Also it might be fun to shitpost about it on twitter.
And MAYBE, just maybe, it will be useful for someone else building their game about space.

## Goals
- World with the size of EVE Online that lives fully on its own
- Procedurally generated configurable world

## Installation
Nothing so fat until I minimally test it.

## Workflow
```C
uns_init();
const unsId sim = uns_create_simulation();

// configure the simulation here

while (!should_stop) {
  uns_step_simulation();
}

uns_destroy_all_simulations();
uns_shutdown();
```

## License
MIT

## Contact
You can the creation of this nonsense on X [@Enapiuz](https://x.com/Enapiuz)
