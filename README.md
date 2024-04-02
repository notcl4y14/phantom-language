# phantom-language

Just a language with JS/TS-like syntax in development.

## Syntax:
"Hello World" program
```ts
log.writeln("Hello World!");
```
Variables
```ts
let x: number = 10;
let y: number = 4;
let z: number = (x + y);

log.writeln(z);  // Outputs "14"
```
Types
```ts
let x: number = 2.5;
let y: string = "D";

let str = x + y;  // Outputs error: Cannot do number + string
let str: string = x + y;  // "2.5D"
let str = (string) x + y; // Casted number to string, "2.5D" too
```
Reference (Probably)
```ts
let item: string = "Apple";
// You can do "let & itemRef" too
let &itemRef: string = item;
itemRef = "Sword";

// item: "Sword"
// itemRef: "Sword"
```

## TODO:
- Nothing yet