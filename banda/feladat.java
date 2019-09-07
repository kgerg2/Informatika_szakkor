import java.util.*;
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

class Beolvaso{
    private byte[] buf=new byte[16384];    //puffer
    private int index;
    private BufferedInputStream in;
    private int bent;
    public Beolvaso(){
        this.in=new BufferedInputStream(System.in);
    }
    public int scan()throws IOException{    //
        if(bent<0)
        throw new InputMismatchException();
        if(index>=bent){
            index=0;
            bent=in.read(buf);
            if(bent<=0)
            return -1;
        }
        return buf[index++];
    }
    public int nextInt()throws IOException{
        int szam=0;
        int n=scan();
        while(isWhiteSpace(n))    //
        	n=scan();
        int neg=1;
        if(n=='-'){               //
            neg=-1;
            n=scan();
        }
        while(!isWhiteSpace(n)){
            if(n>='0'&&n<='9'){
                szam*=10;
                szam+=n-'0';
                n=scan();
            }
            else throw new InputMismatchException();
        }
        return neg*szam;
    }
    private boolean isWhiteSpace(int n){
        if(n==' '||n=='\n'||n=='\r'||n=='\t'||n==-1)
        	return true;
        return false;
    }
}
public class feladat {
//Minta számsorozat beolvasására
//A bemenet 1. sora az számsorozat elememinek n számát tartalmazza
//A 2. sorban n egész szám van egy-egy szóközzel elválasztva
    public feladat() {}
    public static void main(String[] args) throws Exception{
		Beolvaso be=new Beolvaso();
		int n = be.nextInt();	//az első sorban az elemek száma
        int[] A=new int[n];		//ide olvassuk be a számsorozat elemeit

        for(int i=0;i<n;i++){
        	A[i]=be.nextInt();	//
        }

    }
}
