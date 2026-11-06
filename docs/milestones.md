# Milestones

## Milestone 0 — Read one file

**Status:** Completed

### Goal

Create a file-reading command that prints every line of a text file in the
current directory.

### Interface

cgrep FILE

### Acceptance criteria

- Prints every line in the specified text file.
- Reports an error when the file does not exist or cannot be opened.
- Uses dynamically sized input lines

## Milestone 1 — Search one file

**Status:** Completed

### Goal

Convert the file reader into a search command that prints lines containing a
pattern.

### Interface

cgrep PATTERN FILE

### Acceptance criteria

- Prints every line containing the pattern.
- Prints nothing when there are no matches.
- Reports an error when the file does not exist or cannot be read.
- Returns a nonzero exit code for invalid arguments and file errors.

## Milestone 2 - Case insenstive searching

**Status:** Planned

### Interface

cgrep -i PATTERN FILE

### Acceptance criteria

- Without `-i`, matching remains case-sensitive.
- With `-i`, letter case is ignored.
- Invalid options produce a usage message and nonzero exit code.
- Patterns containing spaces still work.