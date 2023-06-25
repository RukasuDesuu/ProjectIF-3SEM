
#pip install PySimpleGUI
from typing import List
import PySimpleGUI as sg

from bd.Core.Services.ContatoraService.ContatoraService import ContatoraService
from bd.Models.Models import ContatoraModel, ReleModel, ReleCod

contatoraService: ContatoraService = ContatoraService()


def cadastro():

    infoMotorlbl = sg.Text("Informações do Motor", key = '-OUT-', font=('rial Bold', 35), expand_x=True, justification='center')
    #Tensao
    tensaolbl = sg.Text("Tensao:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    tensaotxt = sg.Input('', enable_events=True, key='-TENSAO-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Fator de Servico
    fslbl = sg.Text("Fator de Servico (FS):", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    fstxt = sg.Input('', enable_events=True, key='-FS-', font=('Arial Bold', 20), expand_x=True, justification='left') 
    
    #Potencia
    potlbl = sg.Text("Potencia:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    pottxt = sg.Input('', enable_events=True, key='-POT-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Corrente Nominal
    inlbl = sg.Text("Corrente Nominal (IN):", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    intxt = sg.Input('', enable_events=True, key='-IN-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    #Ip/In
    ipinlbl = sg.Text("Ip/In:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    ipintxt = sg.Input('', enable_events=True, key='-IPIN-', font=('Arial Bold', 20), expand_x=True, justification='left') 

    infoProjetolbl = sg.Text("Informações do Projeto", key = '-OUT-', font=('rial Bold', 35), expand_x=True, justification='center')
    #Contatos Abertos
    CAlbl = sg.Text("Contatos Abertos:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    CAspn = sg.Spin([0,1,2,3,4],initial_value=0, readonly=True,  size=15, enable_events=True, key='-CA-')

    #Contatos Fechados
    CFlbl = sg.Text("Contatos Fechados:", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    CFspn = sg.Spin([0,1,2,3,4],initial_value=0, readonly=True,  size=15, enable_events=True, key='-CF-')

    #Tipo de Corrente
    isAClbl = sg.Text("E corrente alternada? (0 = DC, 1 = AC):", key='-OUT-', font=('Arial Bold', 20), expand_x=True, justification='left')
    isACsldr = sg.Slider(range=(0, 1), default_value=0,expand_x=True, enable_events=True, orientation='horizontal', key='-isAC-')

    #Botao Calcular
    Calcbtn = sg.Button('Dimensionar')

    layout = [[infoMotorlbl],
            [tensaolbl, tensaotxt], 
            [fslbl, fstxt], [potlbl, pottxt],
            [inlbl, intxt], [ipinlbl, ipintxt],
            [infoProjetolbl],
            [CAlbl, CAspn], 
            [CFlbl, CFspn], 
            [isAClbl], [isACsldr],
            [Calcbtn]]
    
    window = sg.Window('Input Demo', layout, size=(900, 700), element_justification='c')


    #loop
    while True:
        event, values = window.read()
        print(event, values)
        if event == 'Dimensionar':
            tensao = int(values['-TENSAO-'])
            pot = float(values['-POT-'])
            fs = float(values['-FS-'])
            inom = float(values['-IN-'])
            ipin = float(values['-IPIN-'])
            nca = values['-CA-']
            ncf = values['-CF-']
            isac = values['-isAC-'];
            
            #Contatora
            iminc = inom*1.1

            #Relé Sobrecarga
            ifrt = 0
            if(fs<1.15):
                ifrt = inom*1.15
            elif (fs>=1.15):
                ifrt = inom*1.25

            #if (imax>ifrt&&imin<ifrt){
            #       det1=imax-ifrt;
            #       det2=imin-ifrt;
            #       det=det1+det2;
            
            contats:List[ContatoraModel] = contatoraService.get_all()
            listRelesRange = []
            for contatora in contats:
                for rele in contatora.correntes:
                    if (rele.imax <= 1.2 and rele.imin >= 0.8):
                        listRelesRange.append(rele)

                
            

        if event == sg.WIN_CLOSED or event == 'Exit':
            break




cadastro()