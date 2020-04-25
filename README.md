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

## Information functions

### string.length(str s)

Returns the length of the string `s`.

```chaos
kaos> string.length("hello world")
11
```

### string.is_empty(str s)

Returns whether the string `s` empty or not.

```chaos
kaos> string.is_empty("hello world")
false
kaos> string.is_empty("")
true
```

### string.is_numeric(str s)

Returns `true` if all characters in the string `s` are numeric characters, and there is at least one character, `false` otherwise.

```chaos
kaos> string.is_numeric("01234")
true
kaos> string.is_numeric("01234x")
false
kaos> string.is_numeric(" 01234")
false
kaos> string.is_numeric("")
false
```

### string.is_alpha(str s)

Returns `true` if string `s` only contains alphabetic characters or whitespace and not empty, `false` otherwise.

```chaos
kaos> string.is_alpha("hello world")
true
kaos> string.is_alpha("he11o w0rld")
false
kaos> string.is_alpha(" ")
true
kaos> string.is_alpha("")
false
```

### string.is_alnum(str s)

Returns `true` if string `s` only contains alphanumeric characters or whitespace and not empty, `false` otherwise.

```chaos
kaos> string.is_alnum("he11o w0rld")
true
kaos> string.is_alnum(" ")
true
kaos> string.is_alnum("")
false
```
