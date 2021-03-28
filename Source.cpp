#include <windows.h>
#include "resource.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool choix_texture;
bool texture=false;
HWND hwndcombo,hwndcombo1, hwndcombo2,hwndcombo3, hwndcombo4;

double x,y,z,t,theta;
int nb_objet=0;
TCHAR text0[]=TEXT("<aucune>");
TCHAR text1[]=TEXT("dalles.jpg");
TCHAR text2[]=TEXT("gravier.jpg");
TCHAR text3[]=TEXT("herbe.jpg");
TCHAR text4[]=TEXT("metal_rouil.jpg");
TCHAR text5[]=TEXT("mi-neige.jpg");
TCHAR text6[]=TEXT("mur.jpg");
TCHAR text7[]=TEXT("papier.jpg");
TCHAR text8[]=TEXT("paves.jpg");
TCHAR text9[]=TEXT("quadrillage.jpg");
TCHAR text10[]=TEXT("tole_rouil.jpg");
TCHAR text11[]=TEXT("eau.jpg");
TCHAR text12[]=TEXT("WRLPOOL.mpg");
TCHAR police1[]=TEXT("SERIF");
TCHAR police2[]=TEXT("SANS");
TCHAR police3[]=TEXT("TYPEWRITER");
TCHAR style1[]=TEXT("BOLD");
TCHAR style2[]=TEXT("PLAIN");
TCHAR style3[]=TEXT("ITALIC");
TCHAR style4[]=TEXT("BOLDITALIC");


char urll[30],url2[30],url3[30],url4[30];


float mat[12];



FILE *fich;


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;

TCHAR szAppName[] = TEXT ("prog") ;




int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PSTR szCmdLine, int iCmdShow)
{
     HWND     hwnd ;
     MSG      msg ;
     WNDCLASS wndclass ;
     
     wndclass.style         = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE ;
     wndclass.lpfnWndProc   = WndProc ;
     wndclass.cbClsExtra    = 0 ;
     wndclass.cbWndExtra    = 0 ;
     wndclass.hInstance     = hInstance ;
     wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
     wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
     wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
     wndclass.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU1);
     wndclass.lpszClassName = szAppName ;

     if (!RegisterClass (&wndclass))
     {
          MessageBox (NULL, TEXT ("Ce programme fonctionne exclusivement sous Windows NT!"),
                      szAppName, MB_ICONERROR) ;
          return 0 ;
     }
     
     hwnd = CreateWindow (szAppName, TEXT ("Interface VRML"),
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL) ;
     
     ShowWindow (hwnd, iCmdShow) ;
     UpdateWindow (hwnd) ;
     
     while (GetMessage (&msg, NULL, 0, 0))
     {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
     }
     return msg.wParam ;

}





LRESULT CALLBACK matiere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
TCHAR vIDC_ambientIntensity[10]=TEXT("0.2"),vIDC_DIFFX[10]=TEXT("0.8"),vIDC_DIFFY[10]=TEXT("0.8"),vIDC_DIFFZ[10]=TEXT("0.8"),
		vIDC_EMX[10]=TEXT("0"),vIDC_EMY[10]=TEXT("0"),vIDC_EMZ[10]=TEXT("0"),vIDC_BRIL[10]=TEXT("0.2"),
		vIDC_SPECX[10]=TEXT("0"),vIDC_SPECY[10]=TEXT("0"),vIDC_SPECZ[10]=TEXT("0"),vIDC_TRANSP[10]=TEXT("0");
	
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText(hwnd, IDC_ambientIntensity,vIDC_ambientIntensity);

			SetDlgItemText(hwnd, IDC_DIFFX,vIDC_DIFFX);
			SetDlgItemText(hwnd, IDC_DIFFY,vIDC_DIFFY);
			SetDlgItemText(hwnd, IDC_DIFFZ,vIDC_DIFFZ);
			SetDlgItemText(hwnd, IDC_EMX,vIDC_EMX);
			SetDlgItemText(hwnd, IDC_EMY,vIDC_EMY);
			SetDlgItemText(hwnd, IDC_EMZ,vIDC_EMZ);
			SetDlgItemText(hwnd, IDC_BRIL,vIDC_BRIL);
			SetDlgItemText(hwnd, IDC_SPECX,vIDC_SPECX);
			SetDlgItemText(hwnd, IDC_SPECY,vIDC_SPECY);
			SetDlgItemText(hwnd, IDC_SPECZ,vIDC_SPECZ);
			SetDlgItemText(hwnd, IDC_TRANSP,vIDC_TRANSP);

		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd, IDC_ambientIntensity,vIDC_ambientIntensity,10);
					GetDlgItemText(hwnd, IDC_DIFFX,vIDC_DIFFX,10);
					GetDlgItemText(hwnd, IDC_DIFFY,vIDC_DIFFY,10);
					GetDlgItemText(hwnd, IDC_DIFFZ,vIDC_DIFFZ,10);
					GetDlgItemText(hwnd, IDC_EMX,vIDC_EMX,10);
					GetDlgItemText(hwnd, IDC_EMY,vIDC_EMY,10);
					GetDlgItemText(hwnd, IDC_EMZ,vIDC_EMZ,10);
					GetDlgItemText(hwnd, IDC_BRIL,vIDC_BRIL,10);
					GetDlgItemText(hwnd, IDC_SPECX,vIDC_SPECX,10);
					GetDlgItemText(hwnd, IDC_SPECY,vIDC_SPECY,10);
					GetDlgItemText(hwnd, IDC_SPECZ,vIDC_SPECZ,10);
					GetDlgItemText(hwnd, IDC_TRANSP,vIDC_TRANSP,10);

                   	mat[0] = _wtof(vIDC_ambientIntensity);
					mat[1] = _wtof(vIDC_DIFFX);
					mat[2] = _wtof(vIDC_DIFFY);
					mat[3] = _wtof(vIDC_DIFFZ);
					mat[4] = _wtof(vIDC_EMX);
					mat[5] = _wtof(vIDC_EMY);
					mat[6] = _wtof(vIDC_EMZ);
					mat[7] = _wtof(vIDC_BRIL);
					mat[8] = _wtof(vIDC_SPECX);
					mat[9] = _wtof(vIDC_SPECY);
					mat[10] = _wtof(vIDC_SPECZ);
					mat[11] = _wtof(vIDC_TRANSP);
						
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK cylindre(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Rayon[10]=TEXT("1.0"),vIDC_Hauteur[10]=TEXT("2.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			SetDlgItemText( hwnd, IDC_Hauteur,vIDC_Hauteur);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_HAUT, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);
					GetDlgItemText(hwnd,IDC_Hauteur,vIDC_Hauteur,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
					
					if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
					  choix_texture = TRUE; //texture fixe
					else
					  choix_texture = FALSE; //texture animée
					 
					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");
					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
					  if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
						   
					    }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
					    }
				
					    }
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Cylinder{\n");
					fwprintf(fich,L"radius %s \n height %s\n",vIDC_Rayon, vIDC_Hauteur);
					if(IsDlgButtonChecked(hwnd, IDC_HAUT) == BST_UNCHECKED) fprintf(fich, "top TRUE\n");
					if(IsDlgButtonChecked(hwnd, IDC_BAS) == BST_UNCHECKED) fprintf(fich, "bottom TRUE\n");
					if(IsDlgButtonChecked(hwnd, IDC_COTE) == BST_UNCHECKED) fprintf(fich, "side TRUE\n");
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fprintf(fich,"] }\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK sphere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Rayon[10]=TEXT("1.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
					
					if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
					  choix_texture = TRUE; //texture fixe
					else
					  choix_texture = FALSE; //texture animée
					 
					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");
					
					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
					  if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
						   
					    }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
						

							
					    }
				
					    }
					
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Sphere{\n");
					fwprintf(fich,L"radius %s \n",vIDC_Rayon);
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fprintf(fich,"] }\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}


LRESULT CALLBACK BOX(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"), vIDC_Larg[10]=TEXT("1.0"),vIDC_long[10]=TEXT("2.0"), vIDC_H[10]=TEXT("2.0");
;
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Larg,vIDC_Larg);
			SetDlgItemText( hwnd, IDC_long,vIDC_long);
			SetDlgItemText( hwnd, IDC_H,vIDC_H);

			
			
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText( hwnd, IDC_Larg,vIDC_Larg,10);
					GetDlgItemText( hwnd, IDC_long,vIDC_long,10);
					GetDlgItemText( hwnd, IDC_H,vIDC_H,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
					
					if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
					  choix_texture = TRUE; //texture fixe
					else
					  choix_texture = FALSE; //texture animée
					 
					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");
					
					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
					  if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
						   
					    }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
						    
					  }
				
					    }

					fprintf(fich,"}\n");
					fprintf(fich,"geometry Box{\n");
					fwprintf(fich,L"size %s %s %s \n",vIDC_Larg,vIDC_long,vIDC_H);
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fprintf(fich,"] }\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}


LRESULT CALLBACK cone(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
		  vIDC_Angle[10]=TEXT("0"),vIDC_Rayon[10]=TEXT("1.0"),vIDC_Hauteur[10]=TEXT("2.0");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
			SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
			SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
			SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
			SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
			SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
			SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			SetDlgItemText( hwnd, IDC_Hauteur,vIDC_Hauteur);
			hwndcombo = GetDlgItem (hwnd, IDC_COMBO_FIXE);
			hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text1);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text2);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text3);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text4);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text5);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text6);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text7);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text8);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text9);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text10);
			SendMessage(hwndcombo, CB_ADDSTRING , 0, (LPARAM) text11);
			SendMessage(hwndcombo, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
			SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
			SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
			
			CheckDlgButton(hwnd, IDC_BAS, BST_CHECKED);
			CheckDlgButton(hwnd, IDC_COTE, BST_CHECKED);
			CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
		
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
					GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
					GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
					GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
					GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
					GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
					GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
					GetDlgItemText(hwnd,IDC_Rayon,vIDC_Rayon,10);
					GetDlgItemText(hwnd,IDC_Hauteur,vIDC_Hauteur,10);
					SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
					SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
					
					
					if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
					  choix_texture = TRUE; //texture fixe
					else
					  choix_texture = FALSE; //texture animée
					 
					++nb_objet;
					fopen_s(&fich,"toto.wrl","a");
					fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
					fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
					fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
					fwprintf(fich,L"children Shape {\n");
					fprintf(fich,"appearance Appearance {\n");
					
					if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
					{
					fprintf(fich,"material Material {\n");
					fprintf(fich,"ambientIntensity %g \n",mat[0]);
					fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
					fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
					fprintf(fich,"shininess %g \n",mat[7]);
					fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
					fprintf(fich,"transparency %g \n",mat[11]);
					fprintf(fich,"}\n");
					}
					else {
					  if(choix_texture) 
					    {
					       if (strcmp(urll,"<aucune>")!=0) 
					  				
					       fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
							
					  }				
					  else
					    {
						if (strcmp(url2,"<aucune>")!=0) 
					  		
					       fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
							
					    }
				
					    }
					fprintf(fich,"}\n");
					fprintf(fich,"geometry Cone{\n");
					fwprintf(fich,L"bottomRadius %s \n height %s\n ",vIDC_Rayon, vIDC_Hauteur);
					if(IsDlgButtonChecked(hwnd, IDC_BAS) == BST_UNCHECKED) fprintf(fich, "bottom TRUE\n");
					if(IsDlgButtonChecked(hwnd, IDC_COTE) == BST_UNCHECKED) fprintf(fich, "side TRUE\n");
					fprintf(fich,"}\n");
					fprintf(fich,"}\n");
					fprintf(fich,"},\n");
					fprintf(fich,"] }\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDC_OPTIONS :
					DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
					InvalidateRect (hwnd, NULL, TRUE) ;
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}


LRESULT CALLBACK texte(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    TCHAR vIDC_Dx[10]=TEXT("0"),vIDC_Dy[10]=TEXT("0"),vIDC_Dz[10]=TEXT("0"),vIDC_AxeX[10]=TEXT("1"),vIDC_AxeY[10]=TEXT("0"),vIDC_AxeZ[10]=TEXT("0"),
          vIDC_Angle[10]=TEXT("0"),vIDC_Text[30]=TEXT("Edit me"),vIDC_size[20]=TEXT("10");
    char nom[10]="objet";
    
    switch (msg) {
        case WM_INITDIALOG :
            SetDlgItemText( hwnd, IDC_Dx,vIDC_Dx );
            SetDlgItemText( hwnd, IDC_Dy,vIDC_Dy );
            SetDlgItemText( hwnd, IDC_Dz,vIDC_Dz );
            SetDlgItemText( hwnd, IDC_AxeX,vIDC_AxeX);
            SetDlgItemText( hwnd, IDC_AxeY,vIDC_AxeY);
            SetDlgItemText( hwnd, IDC_AxeZ,vIDC_AxeZ);
            SetDlgItemText( hwnd, IDC_Angle,vIDC_Angle);
            SetDlgItemText( hwnd, IDC_Text,vIDC_Text);
            SetDlgItemText( hwnd, IDC_size,vIDC_size);
            hwndcombo1 = GetDlgItem (hwnd, IDC_COMBO_FIXE);
            hwndcombo2 = GetDlgItem (hwnd, IDC_COMBO_ANIME);
            hwndcombo3 = GetDlgItem (hwnd, IDC_COMBO_police);
            hwndcombo4 = GetDlgItem (hwnd, IDC_COMBO_style);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text0);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text1);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text2);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text3);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text4);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text5);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text6);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text7);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text8);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text9);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text10);
            SendMessage(hwndcombo1, CB_ADDSTRING , 0, (LPARAM) text11);
            SendMessage(hwndcombo1, CB_SETCURSEL , 0, 0);
            SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text0);
            SendMessage(hwndcombo2, CB_ADDSTRING , 0, (LPARAM) text12);
            SendMessage(hwndcombo2, CB_SETCURSEL , 0, 0);
            SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) police1);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) police2);
			SendMessage(hwndcombo3, CB_ADDSTRING , 0, (LPARAM) police3);
            SendMessage(hwndcombo3, CB_SETCURSEL , 0, 0);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) style1);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) style2);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) style3);
			SendMessage(hwndcombo4, CB_ADDSTRING , 0, (LPARAM) style4);
            SendMessage(hwndcombo4, CB_SETCURSEL , 0, 0);
            
            CheckDlgButton(hwnd, IDC_horizontal, BST_CHECKED);
            CheckDlgButton(hwnd, IDC_leftRight, BST_CHECKED);
            CheckDlgButton(hwnd, IDC_upDown, BST_CHECKED);


            CheckRadioButton(hwnd, IDC_RADIO_FIXE, IDC_RADIO_ANIME, IDC_RADIO_FIXE);
			CheckRadioButton(hwnd, IDC_BEGIN, IDC_END, IDC_MIDDLE);
        return 0;
        case WM_COMMAND :
            switch LOWORD(wParam)  {

                case IDOK :
                    GetDlgItemText(hwnd,IDC_Dx,vIDC_Dx,10);
                    GetDlgItemText(hwnd,IDC_Dy,vIDC_Dy,10);
                    GetDlgItemText(hwnd,IDC_Dz,vIDC_Dz,10);
                    GetDlgItemText(hwnd,IDC_AxeX,vIDC_AxeX,10);
                    GetDlgItemText(hwnd,IDC_AxeY,vIDC_AxeY,10);
                    GetDlgItemText(hwnd,IDC_AxeZ,vIDC_AxeZ,10);
                    GetDlgItemText(hwnd,IDC_Angle,vIDC_Angle,10);
                    GetDlgItemText( hwnd, IDC_Text,vIDC_Text,30);
                    GetDlgItemText( hwnd, IDC_size,vIDC_size,20);
                    SendDlgItemMessage(hwnd, IDC_COMBO_FIXE,WM_GETTEXT, sizeof(urll),(LPARAM) urll);
                    SendDlgItemMessage(hwnd, IDC_COMBO_ANIME,WM_GETTEXT, sizeof(url2),(LPARAM) url2);
                    SendDlgItemMessage(hwnd, IDC_COMBO_police,WM_GETTEXT, sizeof(url3),(LPARAM) url3);
                    SendDlgItemMessage(hwnd, IDC_COMBO_style,WM_GETTEXT, sizeof(url4),(LPARAM) url4);
                    
                    if(IsDlgButtonChecked(hwnd, IDC_RADIO_FIXE) == BST_CHECKED)
                      choix_texture = TRUE; //texture fixe
                    else
                      choix_texture = FALSE; //texture animée
                    
                    ++nb_objet;
                    fopen_s(&fich,"toto.wrl","a");
                    fprintf(fich,"DEF %s%d Transform {\n",nom,nb_objet);
                    fwprintf(fich,L"translation %s %s %s\n",vIDC_Dx,vIDC_Dy,vIDC_Dz);
                    fwprintf(fich,L"rotation %s %s %s %s\n",vIDC_AxeX,vIDC_AxeY,vIDC_AxeZ,vIDC_Angle);
                    fwprintf(fich,L"children Shape {\n");
                    fprintf(fich,"appearance Appearance {\n");
					
                    if (IsDlgButtonChecked(hwnd, IDC_OPTIONS) == BST_CHECKED)
                    {
                    fprintf(fich,"material Material {\n");
                    fprintf(fich,"ambientIntensity %g \n",mat[0]);
                    fprintf(fich,"diffuseColor %g %g %g \n",mat[1],mat[2],mat[3]);
                    fprintf(fich,"emissiveColor %g %g %g \n",mat[4],mat[5],mat[6]);
                    fprintf(fich,"shininess %g \n",mat[7]);
                    fprintf(fich,"specularColor %g %g %g \n",mat[8],mat[9],mat[10]);
                    fprintf(fich,"transparency %g \n",mat[11]);
                    fprintf(fich,"}\n");
                    }
                    else {
                      if(choix_texture)
                        {
                           if (strcmp(urll,"<aucune>")!=0)
                                      
                           fwprintf(fich,L"texture ImageTexture { url \".\\textures\\%s\" \n }\n",urll);
						
					  }                
                      else
                        {
                        if (strcmp(url2,"<aucune>")!=0)
                              
                           fwprintf(fich,L"texture MovieTexture { url \".\\textures\\%s\" \n loop TRUE }\n",url2);
							 
					  }
                
                        }
					fprintf(fich,"}\n");
                    fprintf(fich,"geometry Text{\n");
                    fwprintf(fich, L"string[\"\%s\"]\n", vIDC_Text);
                    fwprintf(fich, L"fontStyle FontStyle{\n");
					fwprintf(fich, L"family \"\%s\"\n",url3 );
                    fwprintf(fich, L"style \"\%s\"\n", url4);
                    if(IsDlgButtonChecked(hwnd, IDC_horizontal) == BST_UNCHECKED) fprintf(fich, "horizontal FALSE\n");
					if(IsDlgButtonChecked(hwnd, IDC_END) == BST_CHECKED)
					{
                      fprintf(fich, "justify \"END\"\n");
					}
					else if (IsDlgButtonChecked(hwnd, IDC_MIDDLE) == BST_CHECKED)
					{
						fprintf(fich, "justify \"MIDDLE\"\n");
					}
					else 
					{
						 fprintf(fich, "justify \"BEGIN\"\n");
					}

                    if(IsDlgButtonChecked(hwnd, IDC_leftRight) == BST_UNCHECKED) fprintf(fich, "leftToRight FALSE\n");
                    if(IsDlgButtonChecked(hwnd, IDC_upDown) == BST_UNCHECKED) fprintf(fich, "topToBottom FALSE\n");
                    fprintf(fich, "}\n");
                    fprintf(fich,"}\n");
                    fprintf(fich,"}\n");
                    fprintf(fich,"},\n");
                    fprintf(fich,"] }\n");
					fclose(fich);
                    EndDialog(hwnd, 1);
                    return 0;

                case IDC_OPTIONS :
                    DialogBox(NULL,MAKEINTRESOURCE(IDD_MATIERE), hwnd,(DLGPROC)matiere);
                    InvalidateRect (hwnd, NULL, TRUE) ;
                    return 0;

                case IDCANCEL :
                    
                    EndDialog(hwnd, 0);
                    return 0;
            }
            return 0;

    }
    return 0;
}

LRESULT CALLBACK lum_ponctuelle(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_ambientIntensity[10]=TEXT("0.0"),vIDC_X[10]=TEXT("0"),vIDC_Y[10]=TEXT("0"),vIDC_Z[10]=TEXT("0"),
			vIDC_ROUGE[10]=TEXT("1"),vIDC_VERT[10]=TEXT("1"),vIDC_BLEU[10]=TEXT("1"),vIDC_Rayon[10]=TEXT("100"),
			vIDC_Intensity[10]=TEXT("0"),vIDC_EMY[10]=TEXT("0"),vIDC_EMZ[10]=TEXT("0"),vIDC_EMX[10]=TEXT("1");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_X,vIDC_X );
			SetDlgItemText( hwnd, IDC_Y,vIDC_Y );
			SetDlgItemText( hwnd, IDC_Z,vIDC_Z );
			SetDlgItemText( hwnd, IDC_EMX,vIDC_EMX);
			SetDlgItemText( hwnd, IDC_EMY,vIDC_EMY);
			SetDlgItemText( hwnd, IDC_EMZ,vIDC_EMZ);
			SetDlgItemText( hwnd, IDC_ambientIntensity,vIDC_ambientIntensity);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			SetDlgItemText( hwnd, IDC_Intensity,vIDC_Intensity);
			CheckDlgButton(hwnd, IDC_ON, BST_UNCHECKED);
			
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText( hwnd, IDC_X,vIDC_X,10);
					GetDlgItemText( hwnd, IDC_Y,vIDC_Y ,10);
					GetDlgItemText( hwnd, IDC_Z,vIDC_Z,10);
					GetDlgItemText( hwnd, IDC_EMX,vIDC_EMX,10);
					GetDlgItemText( hwnd, IDC_EMY,vIDC_EMY,10);
					GetDlgItemText( hwnd, IDC_EMZ,vIDC_EMZ,10);
					GetDlgItemText( hwnd, IDC_ambientIntensity,vIDC_ambientIntensity,10);
					GetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon,10);
					GetDlgItemText( hwnd, IDC_Intensity,vIDC_Intensity,10);
					fopen_s(&fich,"toto.wrl","a");	 
					
					fwprintf(fich,L"PointLight{\n");
					fwprintf(fich,L"ambientIntensity %s\n",vIDC_ambientIntensity);
					fwprintf(fich,L"attenuation  %s %s %s\n",vIDC_EMX,vIDC_EMY,vIDC_EMZ);
					fwprintf(fich,L"color  %s %s %s\n",vIDC_ROUGE,vIDC_VERT,vIDC_BLEU);
					fwprintf(fich,L"intensity  %s \n",vIDC_Intensity);
					fwprintf(fich,L"location  %s %s %s\n",vIDC_X,vIDC_Y,vIDC_Z);
					if(IsDlgButtonChecked(hwnd, IDC_ON) == BST_CHECKED) fprintf(fich, "on TRUE\n");
					fwprintf(fich,L"radius  %s\n",vIDC_Rayon);
					fprintf(fich,"}\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK lum_spot(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_ambientIntensity[10]=TEXT("0.0"),vIDC_X[10]=TEXT("0"),vIDC_Y[10]=TEXT("0"),vIDC_Z[10]=TEXT("0"),
			vIDC_ROUGE[10]=TEXT("1"),vIDC_VERT[10]=TEXT("1"),vIDC_BLEU[10]=TEXT("1"),vIDC_Rayon[10]=TEXT("100"),
			vIDC_Intensity[10]=TEXT("0"),vIDC_EMY[10]=TEXT("0"),vIDC_EMZ[10]=TEXT("0"),vIDC_EMX[10]=TEXT("1"),
			vIDC_D1[10]=TEXT("0"),vIDC_D2[10]=TEXT("0"),vIDC_D3[10]=TEXT("-1"),vIDC_Width[10]=TEXT("1.570796"),vIDC_CutOffAngle[10]=TEXT("0.785398");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			SetDlgItemText( hwnd, IDC_X,vIDC_X );
			SetDlgItemText( hwnd, IDC_Y,vIDC_Y );
			SetDlgItemText( hwnd, IDC_Z,vIDC_Z );
			SetDlgItemText( hwnd, IDC_EMX,vIDC_EMX);
			SetDlgItemText( hwnd, IDC_EMY,vIDC_EMY);
			SetDlgItemText( hwnd, IDC_EMZ,vIDC_EMZ);
			SetDlgItemText( hwnd, IDC_D1,vIDC_D1 );
			SetDlgItemText( hwnd, IDC_D2,vIDC_D2 );
			SetDlgItemText( hwnd, IDC_D3,vIDC_D3 );
			SetDlgItemText( hwnd, IDC_CutOffAngle,vIDC_CutOffAngle);
			SetDlgItemText( hwnd, IDC_Width,vIDC_Width);
			SetDlgItemText( hwnd, IDC_ambientIntensity,vIDC_ambientIntensity);
			SetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon);
			SetDlgItemText( hwnd, IDC_Intensity,vIDC_Intensity);
			CheckDlgButton(hwnd, IDC_ON, BST_UNCHECKED);
			
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText( hwnd, IDC_X,vIDC_X,10);
					GetDlgItemText( hwnd, IDC_Y,vIDC_Y ,10);
					GetDlgItemText( hwnd, IDC_Z,vIDC_Z,10);
					GetDlgItemText( hwnd, IDC_EMX,vIDC_EMX,10);
					GetDlgItemText( hwnd, IDC_EMY,vIDC_EMY,10);
					GetDlgItemText( hwnd, IDC_EMZ,vIDC_EMZ,10);
					GetDlgItemText( hwnd, IDC_D1,vIDC_D1,10 );
					GetDlgItemText( hwnd, IDC_D2,vIDC_D2,10 );
					GetDlgItemText( hwnd, IDC_D3,vIDC_D3,10 );
					GetDlgItemText( hwnd, IDC_CutOffAngle,vIDC_CutOffAngle,10);
					GetDlgItemText( hwnd, IDC_Width,vIDC_Width,10);
					GetDlgItemText( hwnd, IDC_ambientIntensity,vIDC_ambientIntensity,10);
					GetDlgItemText( hwnd, IDC_Rayon,vIDC_Rayon,10);
					GetDlgItemText( hwnd, IDC_Intensity,vIDC_Intensity,10);
					fopen_s(&fich,"toto.wrl","a");	 
					
					fwprintf(fich,L"SpotLight{\n");
					fwprintf(fich,L"ambientIntensity %s\n",vIDC_ambientIntensity);
					fwprintf(fich,L"attenuation  %s %s %s\n",vIDC_EMX,vIDC_EMY,vIDC_EMZ);
					fwprintf(fich,L"color  %s %s %s\n",vIDC_ROUGE,vIDC_VERT,vIDC_BLEU);
					fwprintf(fich,L"direction  %s %s %s\n",vIDC_D1,vIDC_D2,vIDC_D3);
					fwprintf(fich,L"cutOffAngle  %s \n",vIDC_CutOffAngle);
					fwprintf(fich,L"beamWidth  %s \n",vIDC_Width);
					fwprintf(fich,L"intensity  %s \n",vIDC_Intensity);
					fwprintf(fich,L"location  %s %s %s\n",vIDC_X,vIDC_Y,vIDC_Z);
					if(IsDlgButtonChecked(hwnd, IDC_ON) == BST_CHECKED) fprintf(fich, "on TRUE\n");
					fwprintf(fich,L"radius  %s\n",vIDC_Rayon);
					fprintf(fich,"}\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK lum_directionnelle(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR vIDC_ambientIntensity[10]=TEXT("0.0"),vIDC_ROUGE[10]=TEXT("1"),vIDC_VERT[10]=TEXT("1"),vIDC_BLEU[10]=TEXT("1"),
			vIDC_Intensity[10]=TEXT("0"),vIDC_D1[10]=TEXT("0"),vIDC_D2[10]=TEXT("0"),vIDC_D3[10]=TEXT("-1");
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			
			SetDlgItemText( hwnd, IDC_D1,vIDC_D1 );
			SetDlgItemText( hwnd, IDC_D2,vIDC_D2 );
			SetDlgItemText( hwnd, IDC_D3,vIDC_D3 );
			SetDlgItemText( hwnd, IDC_ambientIntensity,vIDC_ambientIntensity);
			SetDlgItemText( hwnd, IDC_Intensity,vIDC_Intensity);
			CheckDlgButton(hwnd, IDC_ON, BST_UNCHECKED);
			
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText( hwnd, IDC_D1,vIDC_D1,10 );
					GetDlgItemText( hwnd, IDC_D2,vIDC_D2,10 );
					GetDlgItemText( hwnd, IDC_D3,vIDC_D3,10 );
					GetDlgItemText( hwnd, IDC_ambientIntensity,vIDC_ambientIntensity,10);
					GetDlgItemText( hwnd, IDC_Intensity,vIDC_Intensity,10);
					fopen_s(&fich,"toto.wrl","a");	 
					
					fwprintf(fich,L"DirectionalLight{\n");
					fwprintf(fich,L"ambientIntensity %s\n",vIDC_ambientIntensity);
					fwprintf(fich,L"color  %s %s %s\n",vIDC_ROUGE,vIDC_VERT,vIDC_BLEU);
					fwprintf(fich,L"direction  %s %s %s\n",vIDC_D1,vIDC_D2,vIDC_D3);
					fwprintf(fich,L"intensity  %s \n",vIDC_Intensity);
					if(IsDlgButtonChecked(hwnd, IDC_ON) == BST_CHECKED) fprintf(fich, "on TRUE\n");
					fprintf(fich,"}\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK fond(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR	vIDC_sky1[10]=TEXT("0.0"),vIDC_sky2[10]=TEXT("1.1"),vIDC_sky3[10]=TEXT("1.57"),
			vIDC_RougeS1[10]=TEXT("0"),vIDC_VertS1[10]=TEXT("0"),vIDC_BleuS1[10]=TEXT("1"),
			vIDC_RougeS2[10]=TEXT("0"),vIDC_VertS2[10]=TEXT("0"),vIDC_BleuS2[10]=TEXT("0.5"),
			vIDC_RougeS3[10]=TEXT("0.8"),vIDC_VertS3[10]=TEXT("0.8"),vIDC_BleuS3[10]=TEXT("1"),
			vIDC_RougeS4[10]=TEXT("0.9"),vIDC_VertS4[10]=TEXT("0.9"),vIDC_BleuS4[10]=TEXT("0.9"),
			vIDC_RougeG1[10]=TEXT("0.8"),vIDC_VertG1[10]=TEXT("0.8"),vIDC_BleuG1[10]=TEXT("0.4"),
			vIDC_RougeG2[10]=TEXT("0.8"),vIDC_VertG2[10]=TEXT("0.8"),vIDC_BleuG2[10]=TEXT("0.4"),
			vIDC_RougeG3[10]=TEXT("0.8"),vIDC_VertG3[10]=TEXT("0.8"),vIDC_BleuG3[10]=TEXT("0.7"),
			vIDC_RougeG4[10]=TEXT("0.8"),vIDC_VertG4[10]=TEXT("0.8"),vIDC_BleuG4[10]=TEXT("0.8"),
			vIDC_ground1[10]=TEXT("0.0"),vIDC_ground2[10]=TEXT("1.1"),vIDC_ground3[10]=TEXT("1.57");

	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
			
			SetDlgItemText( hwnd, IDC_sky1,vIDC_sky1 );
			SetDlgItemText( hwnd, IDC_sky2,vIDC_sky2 );
			SetDlgItemText( hwnd, IDC_sky3,vIDC_sky3 );
			SetDlgItemText( hwnd, IDC_ground1,vIDC_ground1 );
			SetDlgItemText( hwnd, IDC_ground2,vIDC_ground2 );
			SetDlgItemText( hwnd, IDC_ground3,vIDC_ground3 );
			SetDlgItemText( hwnd, IDC_RougeS1,vIDC_RougeS1 );
			SetDlgItemText( hwnd, IDC_RougeS2,vIDC_RougeS2 );
			SetDlgItemText( hwnd, IDC_RougeS3,vIDC_RougeS3 );
			SetDlgItemText( hwnd, IDC_RougeS4,vIDC_RougeS4);
			SetDlgItemText( hwnd, IDC_RougeG1,vIDC_RougeG1 );
			SetDlgItemText( hwnd, IDC_RougeG2,vIDC_RougeG2 );
			SetDlgItemText( hwnd, IDC_RougeG3,vIDC_RougeG3 );
			SetDlgItemText( hwnd, IDC_RougeG4,vIDC_RougeG4 );
			SetDlgItemText( hwnd, IDC_VertS1,vIDC_VertS1 );
			SetDlgItemText( hwnd, IDC_VertS2,vIDC_VertS2 );
			SetDlgItemText( hwnd, IDC_VertS3,vIDC_VertS3 );
			SetDlgItemText( hwnd, IDC_VertS4,vIDC_VertS4 );
			SetDlgItemText( hwnd, IDC_VertG1,vIDC_VertG1 );
			SetDlgItemText( hwnd, IDC_VertG2,vIDC_VertG2 );
			SetDlgItemText( hwnd, IDC_VertG3,vIDC_VertG3 );
			SetDlgItemText( hwnd, IDC_VertG4,vIDC_VertG4 );
			SetDlgItemText( hwnd, IDC_BleuS1,vIDC_BleuS1);
			SetDlgItemText( hwnd, IDC_BleuS2,vIDC_BleuS2);
			SetDlgItemText( hwnd, IDC_BleuS3,vIDC_BleuS3);
			SetDlgItemText( hwnd, IDC_BleuS4,vIDC_BleuS4);
			SetDlgItemText( hwnd, IDC_BleuG1,vIDC_BleuG1);
			SetDlgItemText( hwnd, IDC_BleuG2,vIDC_BleuG2);
			SetDlgItemText( hwnd, IDC_BleuG3,vIDC_BleuG3);
			SetDlgItemText( hwnd, IDC_BleuG4,vIDC_BleuG4);
			CheckDlgButton(hwnd, IDC_ON, BST_UNCHECKED);
			
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText( hwnd, IDC_sky1,vIDC_sky1,10 );
					GetDlgItemText( hwnd, IDC_sky2,vIDC_sky2,10 );
					GetDlgItemText( hwnd, IDC_sky3,vIDC_sky3,10 );
					GetDlgItemText( hwnd, IDC_ground1,vIDC_ground1,10 );
					GetDlgItemText( hwnd, IDC_ground2,vIDC_ground2,10 );
					GetDlgItemText( hwnd, IDC_ground3,vIDC_ground3,10 );
					GetDlgItemText( hwnd, IDC_RougeS1,vIDC_RougeS1,10 );
					GetDlgItemText( hwnd, IDC_RougeS2,vIDC_RougeS2,10 );
					GetDlgItemText( hwnd, IDC_RougeS3,vIDC_RougeS3,10 );
					GetDlgItemText( hwnd, IDC_RougeS4,vIDC_RougeS4,10 );
					GetDlgItemText( hwnd, IDC_RougeG1,vIDC_RougeG1,10 );
					GetDlgItemText( hwnd, IDC_RougeG2,vIDC_RougeG2,10 );
					GetDlgItemText( hwnd, IDC_RougeG3,vIDC_RougeG3,10 );
					GetDlgItemText( hwnd, IDC_RougeG4,vIDC_RougeG4,10 );
					GetDlgItemText( hwnd, IDC_VertS1,vIDC_VertS1,10 );
					GetDlgItemText( hwnd, IDC_VertS2,vIDC_VertS2,10 );
					GetDlgItemText( hwnd, IDC_VertS3,vIDC_VertS3,10 );
					GetDlgItemText( hwnd, IDC_VertS4,vIDC_VertS4,10 );
					GetDlgItemText( hwnd, IDC_VertG1,vIDC_VertG1,10);
					GetDlgItemText( hwnd, IDC_VertG2,vIDC_VertG2,10);
					GetDlgItemText( hwnd, IDC_VertG3,vIDC_VertG3,10);
					GetDlgItemText( hwnd, IDC_VertG4,vIDC_VertG4,10);
					GetDlgItemText( hwnd, IDC_BleuS1,vIDC_BleuS1,10);
					GetDlgItemText( hwnd, IDC_BleuS2,vIDC_BleuS2,10);
					GetDlgItemText( hwnd, IDC_BleuS3,vIDC_BleuS3,10);
					GetDlgItemText( hwnd, IDC_BleuS4,vIDC_BleuS4,10);
					GetDlgItemText( hwnd, IDC_BleuG1,vIDC_BleuG1,10);
					GetDlgItemText( hwnd, IDC_BleuG2,vIDC_BleuG2,10);
					GetDlgItemText( hwnd, IDC_BleuG3,vIDC_BleuG3,10);
					GetDlgItemText( hwnd, IDC_BleuG4,vIDC_BleuG4,10);
					fopen_s(&fich,"toto.wrl","a");	 
					
					fwprintf(fich,L"Background{\n");
					fwprintf(fich,L"skyAngle \[ %s %s %s \] \n",vIDC_sky1,vIDC_sky2,vIDC_sky3);
					fwprintf(fich,L"skyColor \[%s %s %s, %s %s %s, %s %s %s, %s %s %s\] \n",vIDC_RougeS1,vIDC_VertS1,vIDC_BleuS1,vIDC_RougeS2,vIDC_VertS2,vIDC_BleuS2,vIDC_RougeS3,vIDC_VertS3,vIDC_BleuS3,vIDC_RougeS4,vIDC_VertS4,vIDC_BleuS4);
					fwprintf(fich,L"skyAngle \[ %s %s %s \] \n",vIDC_sky1,vIDC_sky2,vIDC_sky3);
					fwprintf(fich,L"skyColor \[%s %s %s, %s %s %s, %s %s %s, %s %s %s\] \n",vIDC_RougeG1,vIDC_VertG1,vIDC_BleuG1,vIDC_RougeG2,vIDC_VertG2,vIDC_BleuG2,vIDC_RougeG3,vIDC_VertG3,vIDC_BleuG3,vIDC_RougeG4,vIDC_VertG4,vIDC_BleuG4);
					fprintf(fich,"}\n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK sensor_cylindre(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR   vIDC_diskAngle[10]=TEXT("0.262"),vIDC_maxAngle[10]=TEXT("-1"),vIDC_minAngle[10]=TEXT("0"),vIDC_offSet[10]=TEXT("0");
			
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
					SetDlgItemText( hwnd, IDC_diskAngle,vIDC_diskAngle);
					SetDlgItemText( hwnd, IDC_maxAngle,vIDC_maxAngle);
					SetDlgItemText( hwnd, IDC_minAngle,vIDC_minAngle);
					SetDlgItemText( hwnd, IDC_offSet,vIDC_offSet);
					CheckDlgButton(hwnd, IDC_enabled, BST_UNCHECKED);
					CheckDlgButton(hwnd, IDC_autoOffset, BST_UNCHECKED);
			
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText( hwnd, IDC_diskAngle,vIDC_diskAngle,10);
					GetDlgItemText( hwnd, IDC_maxAngle,vIDC_maxAngle,10);
					GetDlgItemText( hwnd, IDC_minAngle,vIDC_minAngle,10);
					GetDlgItemText( hwnd, IDC_offSet,vIDC_offSet,10);
					
					fopen_s(&fich,"toto.wrl","a");	 
					fwprintf(fich,L"DEF cylsensor CylinderSensor{} \n");
					fwprintf(fich,L"CylinderSensor{\n");
					fwprintf(fich,L"diskAngle   %s\n",vIDC_diskAngle);
					fwprintf(fich,L"maxAngle   %s\n",vIDC_maxAngle);
					fwprintf(fich,L"minAngle  %s \n",vIDC_minAngle);
					fwprintf(fich,L"offset %s\n",vIDC_offSet);
					if(IsDlgButtonChecked(hwnd, IDC_autoOffset) == BST_CHECKED) fprintf(fich, "autoOffset TRUE\n");
					if(IsDlgButtonChecked(hwnd, IDC_enabled ) == BST_CHECKED) fprintf(fich, "enabled TRUE\n");
					fprintf(fich,"isActive \n");
					fprintf(fich,"rotation_changed \n");
					fprintf(fich,"trackPoint_changed \n");
					fprintf(fich,"}\n");
					fprintf(fich,"ROUTE cylsensor.rotation_changed TO objet1.set_rotation \n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}


LRESULT CALLBACK sensor_plane(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR   vIDC_maxPosition1[10]=TEXT("-1"), vIDC_maxPosition2[10]=TEXT("-1"),vIDC_minPosition1[10]=TEXT("0"),
			vIDC_minPosition2[10]=TEXT("0"),vIDC_offset1[10]=TEXT("0"),vIDC_offset2[10]=TEXT("0"),vIDC_offset3[10]=TEXT("0");
			
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
					SetDlgItemText( hwnd, IDC_maxPosition1,vIDC_maxPosition1);
					SetDlgItemText( hwnd, IDC_maxPosition2,vIDC_maxPosition2);
					SetDlgItemText( hwnd, IDC_minPosition1,vIDC_minPosition1);
					SetDlgItemText( hwnd, IDC_minPosition1,vIDC_minPosition2);
					SetDlgItemText( hwnd, IDC_offSet1,vIDC_offset1);
					SetDlgItemText( hwnd, IDC_offSet2,vIDC_offset2);
					SetDlgItemText( hwnd, IDC_offSet3,vIDC_offset3);
					CheckDlgButton(hwnd, IDC_enabled, BST_UNCHECKED);
					CheckDlgButton(hwnd, IDC_autoOffset, BST_UNCHECKED);
			
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					GetDlgItemText( hwnd, IDC_maxPosition1,vIDC_maxPosition1,10);
					GetDlgItemText( hwnd, IDC_maxPosition2,vIDC_maxPosition2,10);
					GetDlgItemText( hwnd, IDC_minPosition1,vIDC_minPosition1,10);
					GetDlgItemText( hwnd, IDC_minPosition1,vIDC_minPosition2,10);
					GetDlgItemText( hwnd, IDC_offSet1,vIDC_offset1,10);
					GetDlgItemText( hwnd, IDC_offSet2,vIDC_offset2,10);
					GetDlgItemText( hwnd, IDC_offSet3,vIDC_offset3,10);
					
					fopen_s(&fich,"toto.wrl","a");	 
					fwprintf(fich,L"DEF capteur PlaneSensor{}  \n");
					fwprintf(fich,L"PlaneSensor{\n");
					fwprintf(fich,L"maxPosition   %s %s\n",vIDC_maxPosition1,vIDC_maxPosition2);
					fwprintf(fich,L"minPosition   %s %s\n",vIDC_minPosition1,vIDC_minPosition2);
					fwprintf(fich,L"offset %s %s %s \n",vIDC_offset1,vIDC_offset2,vIDC_offset3);
					if(IsDlgButtonChecked(hwnd, IDC_autoOffset) == BST_CHECKED) fprintf(fich, "autoOffset TRUE\n");
					if(IsDlgButtonChecked(hwnd, IDC_enabled ) == BST_CHECKED) fprintf(fich, "enabled TRUE\n");
					fprintf(fich,"isActive \n");
					fprintf(fich,"trackPoint_changed  \n");
					fprintf(fich,"translation_changed  \n");
					fprintf(fich,"}\n");
					fprintf(fich,"ROUTE capteur.translation_changed TO objet1.set_translation \n");
					
					
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}

LRESULT CALLBACK sensor_sphere(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	TCHAR   vIDC_offset1[10]=TEXT("0"),vIDC_offset2[10]=TEXT("1"),vIDC_offset3[10]=TEXT("0"),vIDC_offset4[10]=TEXT("0");
			
	char nom[10]="objet";
    
	switch (msg) {
		case WM_INITDIALOG :
					
					SetDlgItemText( hwnd, IDC_offSet1,vIDC_offset1);
					SetDlgItemText( hwnd, IDC_offSet2,vIDC_offset2);
					SetDlgItemText( hwnd, IDC_offSet3,vIDC_offset3);
					SetDlgItemText( hwnd, IDC_offSet4,vIDC_offset4);
					CheckDlgButton(hwnd, IDC_enabled, BST_UNCHECKED);
					CheckDlgButton(hwnd, IDC_autoOffset, BST_UNCHECKED);
			
		return 0;
		case WM_COMMAND :
			switch LOWORD(wParam)  {

				case IDOK :
					
					GetDlgItemText( hwnd, IDC_offSet1,vIDC_offset1,10);
					GetDlgItemText( hwnd, IDC_offSet2,vIDC_offset2,10);
					GetDlgItemText( hwnd, IDC_offSet3,vIDC_offset3,10);
					GetDlgItemText( hwnd, IDC_offSet4,vIDC_offset4,10);
					fopen_s(&fich,"toto.wrl","a");	 
					fwprintf(fich,L"DEF tourneur SphereSensor{}  \n");
					fwprintf(fich,L"SphereSensor{\n");
					fwprintf(fich,L"offset %s %s %s %s\n",vIDC_offset1,vIDC_offset2,vIDC_offset3,vIDC_offset4);
					if(IsDlgButtonChecked(hwnd, IDC_autoOffset) == BST_CHECKED) fprintf(fich, "autoOffset TRUE\n");
					if(IsDlgButtonChecked(hwnd, IDC_enabled ) == BST_CHECKED) fprintf(fich, "enabled TRUE\n");
					fprintf(fich,"isActive \n");
					fprintf(fich,"trackPoint_changed  \n");
					fprintf(fich,"rotation_changed \n");
					fprintf(fich,"}\n");
					fprintf(fich,"ROUTE tourneur.rotation_changed TO objet1.set_rotation \n");
					fclose(fich);
					EndDialog(hwnd, 1);
					return 0;

				case IDCANCEL :
					
					EndDialog(hwnd, 0);
					return 0;
			}
			return 0;

	}
	return 0;
}



LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
     
     HMENU      hMenu ;
     char nom[20]="objet";
	 
	 
     switch (message)
     {
     case WM_COMMAND:
          hMenu = GetMenu (hwnd) ;
          
          switch (LOWORD (wParam))
          {
         

          case ID_EDITION_QUIT :
			   fopen_s(&fich,"toto.wrl","a"); 
			   fprintf(fich,"\n Inline{\n");
			   fprintf(fich,"url \"axes.wrl\" }\n");
			   SendMessage (hwnd, WM_CLOSE, 0, 0) ;
			   fclose(fich);
			   return 0;
			  
          case ID_EDITION_NEW :
			   fopen_s(&fich,"toto.wrl","w");
			   fprintf(fich,"#VRML V2.0 utf8 \n");
			   fprintf(fich,"Group { \n");
			   fprintf(fich,"children [\n");
			   
			   fclose(fich);
			   EnableMenuItem(hMenu, ID_EDITION_NEW, MF_GRAYED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_CYLINDRE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_SPHERE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_BOITE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_CONE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_GEOMETRIE_TEXTE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_DIRECTIONNELLE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_PONCTUELLE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_LUMIERE_SPOT, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_ANIMATION_TRANSLATION, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_ANIMATION_ROTATION, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_FOND_FOND, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_SENSOR_CYLINDRE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_SENSOR_PLANE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_SENSOR_SPHERE, MF_ENABLED);
			   EnableMenuItem(hMenu, ID_EDITION_QUIT, MF_ENABLED);
			   InvalidateRect (hwnd, NULL, TRUE) ;
               return 0;

          
		  
          case ID_GEOMETRIE_CYLINDRE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_CYLINDRE), hwnd, (DLGPROC)cylindre);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
			   return 0;

		  case ID_GEOMETRIE_SPHERE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_SPHERE), hwnd, (DLGPROC)sphere);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_BOITE: 
			  
			  DialogBox(NULL,MAKEINTRESOURCE(IDD_BOITE), hwnd, (DLGPROC)BOX);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

		  case ID_GEOMETRIE_CONE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_CONE), hwnd, (DLGPROC)cone);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_GEOMETRIE_TEXTE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_TEXTE), hwnd, (DLGPROC)texte);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
		  
			case ID_LUMIERE_DIRECTIONNELLE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_DIRECTIONNELLE), hwnd, (DLGPROC)lum_directionnelle);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_PONCTUELLE: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_PONCTUELLE), hwnd, (DLGPROC)lum_ponctuelle);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_LUMIERE_SPOT: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_SPOT), hwnd, (DLGPROC)lum_spot);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_SENSOR_CYLINDRE: 
			  
				DialogBox(NULL,MAKEINTRESOURCE(IDD_SENSOR_CYLINDRE), hwnd, (DLGPROC)sensor_cylindre);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_SENSOR_PLANE: 
			  
				DialogBox(NULL,MAKEINTRESOURCE(IDD_SENSOR_PLANE), hwnd, (DLGPROC)sensor_plane);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			case ID_SENSOR_SPHERE: 
			  
				DialogBox(NULL,MAKEINTRESOURCE(IDD_SENSOR_SPHERE), hwnd, (DLGPROC)sensor_sphere);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;

			
			case ID_ANIMATION_ROTATION: 
			  
               //DialogBox(NULL,MAKEINTRESOURCE(IDD_ANIMROTATE), hwnd, (DLGPROC)animRotate);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;


			case ID_FOND_FOND: 
			  
               DialogBox(NULL,MAKEINTRESOURCE(IDD_FOND), hwnd, (DLGPROC)fond);
			   InvalidateRect (hwnd, NULL, TRUE) ;
			   return 0;
			

		  }
          
          return 0 ;
		  case WM_CLOSE:
	           	DestroyWindow(hwnd);
		
			case WM_DESTROY:
			  PostQuitMessage(0);
			return 0;
     }
         
    return DefWindowProc (hwnd, message, wParam, lParam) ;
}



