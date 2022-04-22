/*
If two dice are thrown, what is the probability that the sum of the two dice will be a prime number?

its a probability based aptitude problem.

we analysis some case :

rolled first dice                  rolled second dice    probabity of occuring event
{1}                                {1,2,4,6}              p1=(1/6)*(4/6)
{2}                                {1,3,5}                p2=(1/6)*(3/6)
{3}                                {2,4}                  p3=(1/6)*(2/4)
{4}                                {1,3}                  p4=(1/6)*(2/4)
{5}                                {2,6}                  p5=(1/6)*(2/4)
{6}                                {1,5}                  p6=(1/6)*(2/4)


the probability that the sum of the two dice will be a prime number=p1+p2+p3+p4+p5+p6=5/12
*/