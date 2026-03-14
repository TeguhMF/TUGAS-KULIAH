/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.tplp035;
import java.util.Scanner;
/**
 *
 * @author teguh
 */
public class App {

    public static void main(String[] args) {
        String nama = "Teguh Maulana Firmansyah";
        System.out.println("Hello Teguh!");
        
        int NilaiAkhir = 83;                                        
        if( NilaiAkhir < 80) {
            System.out.println("Kamu Tidal lulus");
        } else {
            System.out.println("Kamu lulus");           
        }
        Scanner inputData = new Scanner (System.in);
        System.out.print("masukan nama lengkap:");
        
        nama = inputData.nextLine();
        System.out.println("WIWOKDETOK" + nama);
    }
}
