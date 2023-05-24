#!/usr/bin/env python

import cgi
import os
import os.path

# Fonction pour générer le formulaire de connexion
def generate_login_form():
    print("Content-Type: text/html\r\n\r\n")
    print("")
    with open('avocat_now/cgi_test/cgi-bin/login_content/login.html', 'r') as f:
        for ligne in f:
            print(ligne, end='')

# Fonction pour générer la page de déconnexion
def generate_logout_page():
    print("Content-Type: text/html")
 
    print("Set-Cookie: session=; expires=Thu, 01 Jan 1970 00:00:00 GMT")
    print("Set-Cookie: username=; expires=Thu, 01 Jan 1970 00:00:00 GMT")
    print("Set-Cookie: password=; expires=Thu, 01 Jan 1970 00:00:00 GMT\r\n\r\n")
    print("")
 
    print("<html>")
    print("<body>")
    print("<h1>Déconnexion</h1>")
    print("<p>Vous êtes déconnecté.</p>")
    print("<p><a href=\"../../index.html\">Index</a></p>")
    print("<p><a href=\"login.py\">Login</a></p>")
    print("</body>")
    print("</html>")

# Vérifier si le cookie de session existe

def check_session():
    if os.path.isfile('cookies.txt'):
        return True
    return False

# Vérifier les données de connexion
def check_credentials(username, password):
    # Vérification factice des données (exemple)
    if username != 'Zbub':
        return True
    return False

# Récupérer les données POST
form = cgi.FieldStorage()

# Vérifier si l'utilisateur est déjà connecté
if check_session() == True :
    # Afficher la page de déconnexion si l'utilisateur est déjà connecté
        
    # print('======================== COOKIE EXISTE ==================================')

    generate_logout_page()
else:
 
    # print('======================== COOKIE EXISTE PAS ==================================')
 
    # Vérifier si les données de connexion ont été soumises
    if 'username' in form and 'password' in form:

        # print('======================== DATA OBTENUE ==================================')

        username = form.getvalue("username")
        password = form.getvalue("password")

        # Vérifier les informations de connexion
        if check_credentials(username, password):
           
            # print('======================== CREATION DE COOKIE ==================================')
           
            # Créer un cookie de session
            print("Content-Type: text/html")
            print("Set-Cookie: session=loggedin")  # Définir le cookie de session
            print("Set-Cookie: username=", username)  # Définir le cookie de user
            print("Set-Cookie: password=", password, "\r\n\r\n")  # Définir le cookie de password
            print("")

            # with open('avocat_now/cgi_test/cgi-bin/login_content/session_active.html', 'r') as f:
            #     for ligne in f:
            #         print(ligne, end='')



            print("<html>")
            print("<body>")
            print("<h1>Connexion réussie</h1>")
            print("<p>Bienvenue, {}!</p>".format(username))
            print("<p><a href=\"login.py\">Se déconnecter</a></p>")
            print("</body>")
            print("</html>")
        else:
            # Afficher à nouveau le formulaire de connexion avec un message d'erreur
            print("Content-Type: text/html\r\n\r\n")
            print("")
            with open('avocat_now/cgi_test/cgi-bin/login_content/login_invalid.html', 'r') as f:
                for ligne2 in f:
                    print(ligne2, end='')
    else:
        # Afficher le formulaire de connexion
        # print('======================== DEMANDE DATA ==================================')
        generate_login_form()
