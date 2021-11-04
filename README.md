# agame

## dev-notes
branching should be done as follows:
- `master`: where a stable build is found
- `dev`: where we create the game  
- `feature/*`: where a feature is created
- `fix/*`: where we hunt down the :bugs:
```
        The beginning of times      |       When AGAME actually builds

    ???                        ???    master     -----o---------------o----
    ???  just play with this   ???                   /               / 
    ???  no actual branching   ???    dev     --o---/-----o--o-o-o--/---o---o
    ???  since we're just      ???                     \        /
    ???  messing around        ???    feature/*         \--o-o-/
```