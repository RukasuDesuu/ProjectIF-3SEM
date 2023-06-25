from ..BaseService import BaseService
from Models.ContatoraModel import ContatoraModel

class ContatoraService(BaseService):
    def __init__(self) -> None:
        super().__init__(ContatoraModel)