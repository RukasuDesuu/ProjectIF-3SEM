
#pip install PySimpleGUI
import PySimpleGUI as sg

#GUI
#l1 = sg.Text('Type here', key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='center')
#t1 = sg.Input('', enable_events=True, key='-INPUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
#b1 = sg.Button('Ok', key='-OK-', font=('Arial Bold', 20))
#b2 = sg.Button('Exit', font=('Arial Bold', 20))
#layout = [[l1], [t1], [b1, b2]]
#window = sg.Window('Input Demo', layout, size=(750, 150))


def cadastro():
    #Tensao
    tensaolbl = sg.Text("Tensao:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    tensaotxt = sg.Input('', enable_events=True, key='-INPUT-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Fator de Servico
    fslbl = sg.Text("Fator de Servico (FS):", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    fstxt = sg.Input('', enable_events=True, key='-INPUT-', font=('Arial Bold', 20), expand_x=True, justification='left') 
    
    #Potencia
    potlbl = sg.Text("Potencia:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    pottxt = sg.Input('', enable_events=True, key='-INPUT-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Corrente Nominal
    inlbl = sg.Text("Corrente Nominal (IN):", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    intxt = sg.Input('', enable_events=True, key='-INPUT-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Ip/In
    ipinlbl = sg.Text("Ip/In:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    ipintxt = sg.Input('', enable_events=True, key='-INPUT-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Contatos Abertos
    CAlbl = sg.Text("Contatos Abertos:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    CAspn = sg.Spin([0,1,2,3,4],initial_value=0, readonly=True,  size=15, enable_events=True, key='-INPUT-')

    #Contatos Fechados
    CFlbl = sg.Text("Contatos Fechados:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    CFspn = sg.Spin([0,1,2,3,4],initial_value=0, readonly=True,  size=15, enable_events=True, key='-INPUT-')

    #Tipo de Corrente

    #Botao Calcular
    Calcbtn = sg.Button('Dimensionar')

    layout = [[tensaolbl, tensaotxt], [fslbl, fstxt], [potlbl, pottxt], [inlbl, intxt], [ipinlbl, ipintxt], [CAlbl, CAspn], [CFlbl, CFspn], [Calcbtn]]
    window = sg.Window('Input Demo', layout, size=(900, 500), element_justification='c')


    #loop
    while True:
        event, values = window.read()
        print(event, values)
        if event == 'Dimensionar':
            #if values['-INPUT-'][-1] not in ('0123456789'):
            #    sg.popup("Only digits allowed")
            #    window['-INPUT-'].update(values['-INPUT-'][:-1])
            print('robson')
            

        if event == sg.WIN_CLOSED or event == 'Exit':
            break
        #window.close()


cadastro()