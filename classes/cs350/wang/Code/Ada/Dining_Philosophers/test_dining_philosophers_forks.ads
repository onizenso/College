with Synchronization.Generic_Mutexes_Array;

package Test_Dining_Philosophers_Forks is
   type Philosopher is (Aristotle, Kant, Spinoza, Marx, Russel);
   package Forks is
      new Synchronization.Generic_Mutexes_Array (Philosopher);
end Test_Dining_Philosophers_Forks;
