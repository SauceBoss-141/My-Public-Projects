/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.m.queuevialinkedlist;

/**
 *
 * @author jacobbrown
 */
public class LLQueue {
    private class Node{
        private Object data;
        private Node next;
        public Node(){}
        public Node(Object newData, Node nextLink){
            data = newData;
            next = nextLink;
        }   
    }
    
    private Node front;
    private Node back;
    
    public LLQueue(){
            front = null;
            back = null;
        }
    public void enqueue(Object x){
        Node newNode = new Node(x, null);
        if(front == null){
            front = back = newNode;
        }else{
            back.next=newNode;
            back=newNode;
        }
    }
    
    public Object dequeue(){
        if(front==null){
            return null;
        }
        Object temp = front.data;
        front = front.next;
        return temp;
    }
    
    public int size(){
        int s = 0;
        Node temp = front;
        while(temp!=null){
            s++;
    }return s;
    }
    public Object peek(){
        if(front==null){
            return null;
        }
        Object temp = front.data;
        return temp;
    }
    public boolean isEmpty(){
        return size()==0;
    }
    public boolean equals(Object other){
        if(other == null){
            return false;
        }else if(!(other instanceof LLQueue)){
            return false;
        }else{
            LLQueue otherList = (LLQueue) other;
            if(size()!= otherList.size()){
                return false;
            }
            Node position = front;
            Node otherPosition = otherList.front;
            while(position!=null){
                if(!(position.data.equals(otherPosition.data))){
                    return false;
                }
                position = position.next;
                otherPosition = otherPosition.next;
            }
            return true;
        }
    }
    

   
}

