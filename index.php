<?php 
	//Türkçe karakter sorunu için kullandığımız Content-Type HTTP header'i
	header('Content-Type: text/html; charset=utf-8');
	header("Access-Control-Allow-Origin: *");
	header("Access-Control-Allow-Methods : *");
	header("Access-Control-Allow-Headers: *"); 

	if($_GET["mode"] == "get"){
		
		if(file_exists("rotate.txt")){
	   		$dosya = fopen("rotate.txt","r");//Dosya var ve yazmak için aç
		}else{
		    $dosya = fopen("rotate.txt","x+");//Dosya yok, oluştur ve yazmak için aç
		}

	    while (!feof($dosya)) {
	        $thisLine = fgets($dosya);
	    }
	    echo $thisLine;
	    //Dosya ile ilgili yapacak işimiz bitti ise fclose fonksiyonuna $resource değişkenini parametre olarak geçiyoruz.
	    fclose($dosya);

	}else if($_GET["mode"] == "getRing"){

		if(file_exists("ring.txt")){
	   		$dosya = fopen("ring.txt","r");//Dosya var ve yazmak için aç
		}else{
		    $dosya = fopen("ring.txt","x+");//Dosya yok, oluştur ve yazmak için aç
		}

	    while (!feof($dosya)) {
	        $thisLine = fgets($dosya);
	    }
	    echo $thisLine;
	    //Dosya ile ilgili yapacak işimiz bitti ise fclose fonksiyonuna $resource değişkenini parametre olarak geçiyoruz.
	    fclose($dosya);

	}else if($_GET["mode"] == "setRing"){
		$ring = $_GET["ring"];
		if(file_exists("ring.txt")){
	   		$dosya=fopen("ring.txt","w");//Dosya var ve yazmak için aç
		}else{
		    $dosya=fopen("ring.txt","x");//Dosya yok, oluştur ve yazmak için aç
		}

	 	if(fwrite($dosya,$ring)){
		    echo 1;
		}else{
		    echo 0;
		}

		fclose($dosya);

	}else{
		
	    $rotate = $_GET["rotate"];

	   	if(file_exists("rotate.txt")){
	   		$dosya=fopen("rotate.txt","w");//Dosya var ve yazmak için aç
		}else{
		    $dosya=fopen("rotate.txt","x");//Dosya yok, oluştur ve yazmak için aç
		}

	 	if(fwrite($dosya,$rotate)){
		    echo 1;
		}else{
		    echo 0;
		}

		fclose($dosya);

	}

 ?>
