/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.tplp035;

import java.util.Scanner;

/**
 *
 * @author teguh
 */
public class Tugas {
    
    public static void main(String[] args) {
        Scanner inputData = new Scanner(System.in);
        
        System.out.print("Masukan Nama Lengkap: ");
        String nama = inputData.nextLine();
        
        System.out.print("Masukan Kelas: ");
        String kelas = inputData.nextLine();
        
        System.out.print("Masukan Umur: ");
        int umur = inputData.nextInt();
        inputData.nextLine(); 
        
        System.out.print("Masukan Mata Kuliah: ");
        String mataKuliah = inputData.nextLine();
        
        System.out.print("Masukan kalimat sapaan: ");
        String haloNamaSaya = inputData.nextLine(); 
        
        System.out.println("\n-------------------------");
        System.out.println(haloNamaSaya + " " + nama);
        System.out.println("Saya dari kelas " + kelas);
        System.out.println("Umur saya " + umur + " tahun");
        System.out.println("Saat ini saya sedang belajar " + mataKuliah);              
    }
}
