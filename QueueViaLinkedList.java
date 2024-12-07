/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.m.queuevialinkedlist;

/**
 *
 * @author jacobbrown
 */
public class QueueViaLinkedList {
   

    public static void main(String[] args) {
         String target = "Somethings!";
        String palindrome = "a man a plan canal panama";
        LLQueue list = new LLQueue();
        // objects to be added to list
        Object object1 = (Character) target.charAt(4);
        Object object2 = (Character) target.charAt(1);
        Object object3 = (Character) target.charAt(2);
        Object object4 = (Character) target.charAt(9);
        Object object20 = (Character) target.charAt(6); 
        
        list.enqueue(object1);
        list.enqueue(object2);
        list.enqueue(object3);
        list.enqueue(object4);
        System.out.println("My list has " + list.size() + " nodes.");
        
        //testing equals
        LLQueue list2 = new LLQueue();
        // add 4 objects to the new linked list
        list2.enqueue(object1);//t
        list2.enqueue(object2);//o
        list2.enqueue(object3);//m
        list2.enqueue(object4);//s
        boolean isEqual2 = list.equals(list2);
        System.out.println("list2 is equal to list1? " + isEqual2);
        
        // add 4 objects to our linked list in a different order
        LLQueue list3 = new LLQueue();
        list3.enqueue(object3);//m
        list3.enqueue(object1);//t
        list3.enqueue(object2);//o
        list3.enqueue(object4);//s
        boolean isEqual3 = list.equals(list3);
        System.out.println("list3 is equal to list1? " + isEqual3);
        
        // testing isEmpty() and poll()
        while(!list.isEmpty()) {
            Object temp = list.dequeue();
            System.out.println("Polling " + temp);

    }
    }
}
