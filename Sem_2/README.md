
| ID задания | Код | Схема | Расположение |
| :----: | :----: | :----: | :----: |
| №4 | ✅ | ✅ | 1_L |
| Пузырёк | ✅ | ✅ | sorting |
| Выбор | ✅ | ✅ | sorting |
| Вставки | ✅ | ✅ | sorting |
| №5 | ✅ | ✅ | 2_L |
| Ханой | ✅ | ✅ | tower |
| 8 ферзей | ✅ | ✅ | queen |
| №7.1 | ✅ | ❌ | 5_1_L |
| №7.2 | ✅ | ❌ | 5_2_L |
| №6 | ✅ | ❌ | 3_L |
| №10 | ✅ | ❌ | 4_L |
| №11.1 | ❌ | ❌ |  |
| №11.2 | ❌ | ❌ |  |
| №11.3 | ❌ | ❌ |  |
| №11.4 | ❌ | ❌ |  |
| idef0 | ❌ | ❌ |  |
| №9 | ✅ | ❌ | 6_L |
- uses: Platane/snk@v3
  with:
    # github user name to read the contribution graph from (**required**)
    # using action context var `github.repository_owner` or specified user
    github_user_name: ${{ github.repository_owner }}

    # list of files to generate.
    # one file per line. Each output can be customized with options as query string.
    #
    #  supported options:
    #  - palette:     A preset of color, one of [github, github-dark, github-light]
    #  - color_snake: Color of the snake
    #  - color_dots:  Coma separated list of dots color.
    #                 The first one is 0 contribution, then it goes from the low contribution to the highest.
    #                 Exactly 5 colors are expected.
    outputs: |
      dist/github-snake.svg
      dist/github-snake-dark.svg?palette=github-dark
      dist/ocean.gif?color_snake=orange&color_dots=#bfd6f6,#8dbdff,#64a1f4,#4b91f1,#3c7dd9
