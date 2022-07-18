/*
//virus =coronavirus
//sample =corovirusa
// result is positive, as all chars of sample are present in virus and in same order

//sample =viruscoro
// result is negative, as chars are not present in order
*/

let virus="coronavirus";
let sample="corovirus";
let counter=0;
for(let i=0,j=0;i<virus.length && j<sample.length;i++,j++){
    if(virus[i]==sample[j]){
        i++;
        j++;
        counter++;
    }else if(virus[i]!=sample[j]){

        i++;
    }else {

    }
}
if(counter==sample.length) return true;


