
 const fruits = [3, 30, 34, 5, 9];
 fruits.sort(cmp);
 function cmp(a,b){
   console.log(a-b);
  return a-b;

 }
 console.log(fruits);

 const numbers = [4, 2, 5, 1, 3];
 numbers.sort(function(x, y) {
  let k1=x-y; 
  let k2=y-x; 
  return k2>k1;
});
console.log(numbers);
  