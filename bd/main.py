from Core.Services.ContatoraService.ContatoraService import ContatoraService
from Models.ContatoraModel import ContatoraModel, ReleModel

if __name__ == "__main__":
    contatoraService: ContatoraService = ContatoraService()

    contatora: ContatoraModel  = contatoraService.get_by_id(1)

    print("oi")
    