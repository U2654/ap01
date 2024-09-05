Console.Write("a: ");            // read using system functions
int a = Convert.ToInt32(         // typed a is integer, but console
    Console.ReadLine());         // reads string that must be converted to int
Console.Write("b: ");             
int b = Convert.ToInt32(
    Console.ReadLine());

if (a == b) {                   // blocks are structured by { }
    Console.Write("equal");
} else {
    Console.Write("not equal");
}
