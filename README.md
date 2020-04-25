String library of the Chaos language. You can install this spell with:

```bash
occultist install string
```

and import it with:

```chaos
import string
```

## String operations

### string.replace(str target, str needle, str replacement)

Replace all occurrences of the `needle` string with the `replacement` string.

```chaos
kaos> string.replace("hello world", "world", "friend")
hello friend
```

### string.upper(str s)

Make the all characters in string `s` uppercase.

```chaos
kaos> string.upper("hello world")
HELLO WORLD
```

### string.lower(str s)

Make the all characters in string `s` lowercase.

```chaos
kaos> import string
kaos> string.lower("HeLlO WoRLd")
hello world
```

### string.capitalize(str s)

Capitalize the string `s`.

```chaos
kaos> string.capitalize("hello world")
Hello world
```

### string.concat(str s1, str s2)

Concatenate string `s1` and string `s2`.

```chaos
kaos> string.concat("hello", " world")
hello world
```
