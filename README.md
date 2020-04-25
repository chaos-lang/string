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
